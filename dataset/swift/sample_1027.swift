swift
func update_velocity(pos: Double, vel: Double, best_pos: Double, global_best: Double) -> Double {
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let r1 = 0.5
    let r2 = 0.5
    let new_vel = w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos)
    return new_vel
}

func update_position(pos: Double, vel: Double) -> Double {
    return pos + vel
}

func optimize(func: (Double) -> Double, bounds: (Double, Double), n_particles: Int = 30, max_iter: Int = 1000) {
    var particles = stride(from: bounds.0, to: bounds.1, by: (bounds.1 - bounds.0) / Double(n_particles)).map { $0 }
    var velocities = Array(repeating: 0.0, count: n_particles)
    var personal_best = particles
    var global_best = particles.min(by: { func($0) < func($1) })!

    func iterate(i: Int) {
        for j in 0..<n_particles {
            velocities[j] = update_velocity(pos: particles[j], vel: velocities[j], best_pos: personal_best[j], global_best: global_best)
            particles[j] = update_position(pos: particles[j], vel: velocities[j])
            if func(particles[j]) < func(personal_best[j]) {
                personal_best[j] = particles[j]
            }
        }
        global_best = personal_best.min(by: { func($0) < func($1) })!
        iterate(i: i + 1)
    }
    iterate(i: 0)
}

func main() {
    func test_func(_ x: Double) -> Double {
        return x * x
    }
    let bounds = (-100.0, 100.0)
    optimize(func: test_func, bounds: bounds)
}

main()