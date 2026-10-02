import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int) {
        position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        bestPosition = position
        bestScore = .infinity
    }

    func updateVelocity(globalBest: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (globalBest[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition() {
        for i in 0..<position.count {
            position[i] += velocity[i]
            if position[i] < -10 {
                position[i] = -10
            } else if position[i] > 10 {
                position[i] = 10
            }
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]
    var globalBestScore: Double

    init(numParticles: Int, dimensions: Int) {
        particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        globalBest = (0..<dimensions).map { _ in .infinity }
        globalBestScore = .infinity
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBest = particle.bestPosition
                globalBestScore = particle.bestScore
            }
        }
    }

    func optimize(iterations: Int, w: Double, c1: Double, c2: Double) {
        for _ in 0..<iterations {
            updateGlobalBest()
            for particle in particles {
                particle.updateVelocity(globalBest: globalBest, w: w, c1: c1, c2: c2)
                particle.updatePosition()
            }
        }
    }
}

func objectiveFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let dimensions = 30
    let numParticles = 30
    let iterations = 100
    let w = 0.7
    let c1 = 2.0
    let c2 = 2.0
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions)
    for particle in swarm.particles {
        let score = objectiveFunction(x: particle.position)
        if score < particle.bestScore {
            particle.bestScore = score
        }
    }
    swarm.optimize(iterations: iterations, w: w, c1: c1, c2: c2)
    let bestScore = swarm.globalBestScore
    print("Best Score: \(bestScore)")
}

main()