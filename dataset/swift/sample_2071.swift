import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPos: [Double]
    var bestScore: Double

    init(dim: Int, bounds: [(Double, Double)]) {
        self.position = (0..<dim).map { _ in Double.random(in: bounds[$0].0...bounds[$0].1) }
        self.velocity = (0..<dim).map { _ in Double.random(in: -1...1) }
        self.bestPos = self.position
        self.bestScore = Double.greatestFiniteMagnitude
    }

    func updateVelocity(globalBest: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPos[i] - position[i])
            let social = c2 * r2 * (globalBest[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition(bounds: [(Double, Double)]) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(bounds[i].0, min(position[i], bounds[i].1))
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]
    var globalBestScore: Double

    init(dim: Int, numParticles: Int, bounds: [(Double, Double)]) {
        self.particles = (0..<numParticles).map { _ in Particle(dim: dim, bounds: bounds) }
        self.globalBest = (0..<dim).map { _ in Double.greatestFiniteMagnitude }
        self.globalBestScore = Double.greatestFiniteMagnitude
    }

    func updateGlobalBest() {
        for particle in particles {
            let score = evaluate(position: particle.position)
            if score < globalBestScore {
                globalBest = particle.position
                globalBestScore = score
                particle.bestScore = score
                particle.bestPos = particle.position
            }
        }
    }

    func evaluate(position: [Double]) -> Double {
        return position.map { $0 * $0 }.reduce(0, +)
    }

    func run(iterations: Int) {
        for _ in 0..<iterations {
            for particle in particles {
                particle.updateVelocity(globalBest: globalBest)
                particle.updatePosition(bounds: particles.first!.position.map { ($0, $0) })
            }
            updateGlobalBest()
        }
    }
}

func main() {
    let dim = 3
    let numParticles = 20
    let bounds = (0..<dim).map { _ in (-10.0, 10.0) }
    let swarm = Swarm(dim: dim, numParticles: numParticles, bounds: bounds)
    swarm.run(iterations: 100)
    print("Global Best Position:", swarm.globalBest)
    print("Global Best Score:", swarm.globalBestScore)
}

main()