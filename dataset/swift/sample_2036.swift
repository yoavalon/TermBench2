import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int, lowerBound: Double, upperBound: Double) {
        self.position = (0..<dimensions).map { _ in Double.random(in: lowerBound...upperBound) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestScore = .infinity
    }

    func updateVelocity(globalBestPosition: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            velocity[i] = w * velocity[i] + c1 * r1 * (bestPosition[i] - position[i]) + c2 * r2 * (globalBestPosition[i] - position[i])
        }
    }

    func updatePosition() {
        for i in 0..<position.count {
            position[i] += velocity[i]
        }
    }

    func evaluate(fitnessFunction: ([Double]) -> Double) {
        let currentScore = fitnessFunction(position)
        bestScore = min(bestScore, currentScore)
        if bestScore < currentScore {
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBestPosition: [Double]
    var globalBestScore: Double

    init(size: Int, dimensions: Int, lowerBound: Double, upperBound: Double) {
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions, lowerBound: lowerBound, upperBound: upperBound) }
        self.globalBestPosition = (0..<dimensions).map { _ in Double.random(in: lowerBound...upperBound) }
        self.globalBestScore = .infinity
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBestScore = particle.bestScore
                globalBestPosition = particle.bestPosition
            }
        }
    }

    func iterate(fitnessFunction: ([Double]) -> Double, w: Double, c1: Double, c2: Double) {
        for particle in particles {
            particle.updateVelocity(globalBestPosition: globalBestPosition, w: w, c1: c1, c2: c2)
            particle.updatePosition()
            particle.evaluate(fitnessFunction: fitnessFunction)
        }
        updateGlobalBest()
    }
}

func fitnessFunction(position: [Double]) -> Double {
    return position.reduce(0) { $0 + ($1 * $1) }
}

func main() {
    let dimensions = 2
    let lowerBound = -10.0
    let upperBound = 10.0
    let swarmSize = 30
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let iterations = 100
    let swarm = Swarm(size: swarmSize, dimensions: dimensions, lowerBound: lowerBound, upperBound: upperBound)
    for _ in 0..<iterations {
        swarm.iterate(fitnessFunction: fitnessFunction, w: w, c1: c1, c2: c2)
    }
    print("Global best score:", swarm.globalBestScore)
    print("Global best position:", swarm.globalBestPosition)
}

main()