import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var pbest: [Double]
    var pbest_value: Double

    init(dim: Int) {
        position = [Double](repeating: 0.0, count: dim)
        velocity = [Double](repeating: 0.0, count: dim)
        pbest = [Double](repeating: 0.0, count: dim)
        pbest_value = .infinity
    }

    func update_velocity(gbest: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
        for i in 0..<position.count {
            let r1 = 0.5
            let r2 = 0.5
            velocity[i] = w * velocity[i] + c1 * r1 * (pbest[i] - position[i]) + c2 * r2 * (gbest[i] - position[i])
        }
    }

    func update_position(bounds: [[Double]]) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(bounds[i][0], min(bounds[i][1], position[i]))
        }
    }

    func update_pbest(value: Double) {
        if value < pbest_value {
            pbest = position
            pbest_value = value
        }
    }
}

class Swarm {
    var particles: [Particle]
    var gbest: [Double]
    var gbest_value: Double
    var bounds: [[Double]]

    init(num_particles: Int, dim: Int, bounds: [[Double]]) {
        particles = (0..<num_particles).map { _ in Particle(dim: dim) }
        gbest = [Double](repeating: 0.0, count: dim)
        gbest_value = .infinity
        self.bounds = bounds
    }

    func update_gbest() {
        for particle in particles {
            if particle.pbest_value < gbest_value {
                gbest = particle.pbest
                gbest_value = particle.pbest_value
            }
        }
    }

    func iterate() {
        for particle in particles {
            particle.update_velocity(gbest: gbest)
            particle.update_position(bounds: bounds)
            particle.update_pbest(value: objective_function(x: particle.position))
        }
    }
}

func objective_function(x: [Double]) -> Double {
    return x.reduce(0) { $0 + ($1 * $1) }
}

func optimize(num_particles: Int, dim: Int, max_iterations: Int, bounds: [[Double]]) -> ([Double], Double) {
    let swarm = Swarm(num_particles: num_particles, dim: dim, bounds: bounds)
    for _ in 0..<max_iterations {
        swarm.iterate()
        swarm.update_gbest()
    }
    return (swarm.gbest, swarm.gbest_value)
}

func main() {
    let num_particles = 30
    let dim = 2
    let max_iterations = 100
    let bounds = [(-10.0, 10.0)] * dim
    let (best_position, best_value) = optimize(num_particles: num_particles, dim: dim, max_iterations: max_iterations, bounds: bounds)
    print("Best position:", best_position)
    print("Best value:", best_value)
}

main()