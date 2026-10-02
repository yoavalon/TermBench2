import Foundation

class Swarm {
    
    var particles: [Particle]
    var best: Particle
    
    init(size: Int) {
        particles = (0..<size).map { _ in Particle(x: Double.random(in: -1...1), y: Double.random(in: -1...1)) }
        best = particles.min(by: { $0.evaluate() < $1.evaluate() })!
    }
    
    func update() {
        for particle in particles {
            particle.updateVelocity(globalBest: best)
            particle.move()
        }
        best = particles.min(by: { $0.evaluate() < $1.evaluate() })!
    }
}

class Particle {
    
    var position: [Double]
    var velocity: [Double]
    var best: [Double]
    
    init(x: Double, y: Double) {
        position = [x, y]
        velocity = [Double.random(in: -0.1...0.1), Double.random(in: -0.1...0.1)]
        best = position
    }
    
    func evaluate() -> Double {
        return -(position[0] * position[0] + position[1] * position[1])
    }
    
    func updateVelocity(globalBest: Particle) {
        let inertia = 0.7
        let cognitive = 1.5
        let social = 1.5
        for i in 0..<velocity.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitiveComponent = cognitive * r1 * (best[i] - position[i])
            let socialComponent = social * r2 * (globalBest.position[i] - position[i])
            velocity[i] = inertia * velocity[i] + cognitiveComponent + socialComponent
        }
    }
    
    func move() {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(-1, min(1, position[i]))
        }
        if evaluate() < best[0] {
            best = position
        }
    }
}

func run() {
    let swarmSize = 30
    let swarm = Swarm(size: swarmSize)
    while true {
        swarm.update()
    }
}

run()