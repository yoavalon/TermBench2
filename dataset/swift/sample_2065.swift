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
        for i in 0..<velocity.count {
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
            position[i] = max(-10, min(10, position[i]))
        }
    }

    func evaluate(objectiveFunction: ( [Double]) -> Double) {
        let score = objectiveFunction(position)
        if score < bestScore {
            bestScore = score
            bestPosition = position
        }
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

    func optimize(objectiveFunction: ( [Double]) -> Double, w: Double, c1: Double, c2: Double, iterations: Int) {
        for _ in 0..<iterations {
            for particle in particles {
                particle.updateVelocity(globalBestPosition: globalBestPosition, w: w, c1: c1, c2: c2)
                particle.updatePosition()
                particle.evaluate(objectiveFunction: objectiveFunction)
            }
            updateGlobalBest()
        }
    }
}

func objectiveFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let dimensions = 3
    let numParticles = 10
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let iterations = 50
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions)
    swarm.optimize(objectiveFunction: objectiveFunction, w: w, c1: c1, c2: c2, iterations: iterations)
    print("Best position:", swarm.globalBestPosition)
    print("Best score:", swarm.globalBestScore)
}

main()