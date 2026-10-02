func updateVelocity(particles: inout [[Double]], velocities: inout [[Double]], pbest: [[Double]], gbest: [Double], w: Double, c1: Double, c2: Double) {
    for i in 0..<particles.count {
        for j in 0..<particles[i].count {
            let r1 = 0.5
            let r2 = 0.5
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j])
        }
    }
}

func updatePosition(particles: inout [[Double]], velocities: [[Double]]) {
    for i in 0..<particles.count {
        for j in 0..<particles[i].count {
            particles[i][j] += velocities[i][j]
        }
    }
}

func optimize(particles: inout [[Double]], velocities: inout [[Double]], pbest: inout [[Double]], gbest: inout [Double], w: Double, c1: Double, c2: Double) {
    while true {
        updateVelocity(particles: &particles, velocities: &velocities, pbest: pbest, gbest: gbest, w: w, c1: c1, c2: c2)
        updatePosition(particles: &particles, velocities: velocities)
        for i in 0..<particles.count {
            if pbest[i][0] > particles[i][0] {
                pbest[i] = particles[i]
            }
        }
        let minParticle = particles.min { $0[0] < $1[0] }!
        if gbest[0] > minParticle[0] {
            gbest = minParticle
        }
    }
}

func main() {
    var particles = [[1.0, 2.0], [3.0, 4.0], [5.0, 6.0]]
    var velocities = [[0.0, 0.0], [0.0, 0.0], [0.0, 0.0]]
    var pbest = particles
    var gbest = particles.min { $0[0] < $1[0] }!
    let w = 0.5
    let c1 = 1.5
    let c2 = 1.5
    optimize(particles: &particles, velocities: &velocities, pbest: &pbest, gbest: &gbest, w: w, c1: c1, c2: c2)
}

main()