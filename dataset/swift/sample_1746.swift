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

    func updateVelocity(globalBestPosition: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
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
        }
    }

    func evaluate(costFunction: (Particle) -> Double) {
        let score = costFunction(self)
        if score < bestScore {
            bestScore = score
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBestPosition: [Double]?
    var globalBestScore: Double

    init(size: Int, dimensions: Int) {
        particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
        globalBestScore = .infinity
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBestScore = particle.bestScore
                globalBestPosition = particle.bestPosition
            }
        }
    }

    func updateSwarm() {
        for particle in particles {
            particle.updateVelocity(globalBestPosition: globalBestPosition ?? [])
            particle.updatePosition()
        }
    }
}

func costFunction(particle: Particle) -> Double {
    return particle.position.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let dimensions = 10
    let swarmSize = 20
    let swarm = Swarm(size: swarmSize, dimensions: dimensions)
    while true {
        for particle in swarm.particles {
            particle.evaluate(costFunction: costFunction)
        }
        swarm.updateGlobalBest()
        swarm.updateSwarm()
    }
}

main()