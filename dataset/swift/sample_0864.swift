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
        bestScore = Double.greatestFiniteMagnitude
    }

    func updateVelocity(globalBestPosition: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (globalBestPosition[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition() {
        for i in 0..<position.count {
            position[i] += velocity[i]
        }
    }

    func evaluate(fitnessFunction: ([Double]) -> Double) {
        bestScore = fitnessFunction(position)
        return bestScore
    }
}

class Swarm {
    var particles: [Particle]
    var globalBestPosition: [Double]
    var globalBestScore: Double

    init(numParticles: Int, dimensions: Int) {
        particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        globalBestPosition = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        globalBestScore = Double.greatestFiniteMagnitude
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBestScore = particle.bestScore
                globalBestPosition = particle.bestPosition
            }
        }
    }
}

func fitnessFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + $1 * $1 }
}

func optimize(swarm: Swarm, w: Double, c1: Double, c2: Double, iterations: Int) -> ([Double], Double) {
    for _ in 0..<iterations {
        for particle in swarm.particles {
            particle.updateVelocity(globalBestPosition: swarm.globalBestPosition, w: w, c1: c1, c2: c2)
            particle.updatePosition()
            particle.evaluate(fitnessFunction: fitnessFunction)
        }
        swarm.updateGlobalBest()
    }
    return (swarm.globalBestPosition, swarm.globalBestScore)
}

func main() {
    let dimensions = 10
    let numParticles = 20
    let w = 0.7
    let c1 = 2.0
    let c2 = 2.0
    let iterations = 100
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions)
    let (bestPosition, bestScore) = optimize(swarm: swarm, w: w, c1: c1, c2: c2, iterations: iterations)
    print("Best position:", bestPosition)
    print("Best score:", bestScore)
}

main()