import Foundation

func updateVelocity(particles: inout [[Double]], velocities: inout [[Double]], pbest: [[Double]], gbest: [Double], w: Double, c1: Double, c2: Double) {
    for i in 0..<particles.count {
        for j in 0..<particles[i].count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
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

func optimize(particles: inout [[Double]], velocities: inout [[Double]], pbest: [[Double]], gbest: [Double], w: Double, c1: Double, c2: Double) {
    updateVelocity(particles: &particles, velocities: &velocities, pbest: pbest, gbest: gbest, w: w, c1: c1, c2: c2)
    updatePosition(particles: &particles, velocities: velocities)
    optimize(particles: &particles, velocities: &velocities, pbest: pbest, gbest: gbest, w: w, c1: c1, c2: c2)
}

func fitness(position: [Double]) -> Double {
    return position.reduce(0) { $0 + ($1 * $1) }
}

func main() {
    let numParticles = 10
    let dimensions = 2
    var particles = [[Double]](repeating: [Double](repeating: 0, count: dimensions), count: numParticles)
    var velocities = [[Double]](repeating: [Double](repeating: 0, count: dimensions), count: numParticles)
    
    for i in 0..<numParticles {
        for j in 0..<dimensions {
            particles[i][j] = Double.random(in: -10...10)
            velocities[i][j] = Double.random(in: -1...1)
        }
    }
    
    let pbest = particles
    let gbest = particles.min(by: { fitness(position: $0) < fitness(position: $1) })!
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    
    optimize(particles: &particles, velocities: &velocities, pbest: pbest, gbest: gbest, w: w, c1: c1, c2: c2)
}

main()