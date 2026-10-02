import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int, bounds: (Double, Double)) {
        self.position = (0..<dimensions).map { _ in Double.random(in: bounds.0...bounds.1) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestScore = .infinity
    }

    func updateVelocity(globalBest: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
        for i in 0..<velocity.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            velocity[i] = w * velocity[i] + c1 * r1 * (bestPosition[i] - position[i]) + c2 * r2 * (globalBest[i] - position[i])
        }
    }

    func updatePosition(bounds: (Double, Double)) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(bounds.0, min(bounds.1, position[i]))
        }
    }

    func evaluate(objectiveFunction: ObjectiveFunction) {
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

    init(numParticles: Int, dimensions: Int, bounds: (Double, Double)) {
        particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions, bounds: bounds) }
        globalBestPosition = particles[0].position
        globalBestScore = particles[0].bestScore
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBestScore = particle.bestScore
                globalBestPosition = particle.bestPosition
            }
        }
    }

    func iterate(objectiveFunction: ObjectiveFunction) {
        for particle in particles {
            particle.updateVelocity(globalBest: globalBestPosition)
            particle.updatePosition(bounds: objectiveFunction.bounds)
            particle.evaluate(objectiveFunction: objectiveFunction)
        }
        updateGlobalBest()
    }
}

class ObjectiveFunction {
    let bounds: (Double, Double)

    init(bounds: (Double, Double)) {
        self.bounds = bounds
    }

    func callAsFunction(_ position: [Double]) -> Double {
        let x = position[0]
        let y = position[1]
        return pow(x * x + y - 11, 2) + pow(x + y * y - 7, 2)
    }
}

func main() {
    let dimensions = 2
    let numParticles = 30
    let bounds = (-5, 5)
    let objectiveFunction = ObjectiveFunction(bounds: bounds)
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions, bounds: bounds)
    for _ in 0..<100 {
        swarm.iterate(objectiveFunction: objectiveFunction)
        if swarm.globalBestScore < 1e-06 {
            break
        }
    }
    print("Best position:", swarm.globalBestPosition)
    print("Best score:", swarm.globalBestScore)
}

main()