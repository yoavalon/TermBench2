import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var maxVelocity: Double
    var bestFitness: Double = Double.greatestFiniteMagnitude

    init(dimensions: Int, maxVelocity: Double) {
        self.position = Array(repeating: 0.0, count: dimensions)
        self.velocity = Array(repeating: 0.0, count: dimensions)
        self.bestPosition = Array(repeating: 0.0, count: dimensions)
        self.maxVelocity = maxVelocity
    }

    func updateVelocity(globalBest: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (globalBest[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
            velocity[i] = max(-maxVelocity, min(velocity[i], maxVelocity))
        }
    }

    func updatePosition() {
        for i in 0..<position.count {
            position[i] += velocity[i]
        }
    }

    func evaluate(objectiveFunction: ([Double]) -> Double) {
        fitness = objectiveFunction(position)
        if fitness < bestFitness {
            bestFitness = fitness
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]
    var globalBestFitness: Double = Double.greatestFiniteMagnitude

    init(dimensions: Int, populationSize: Int, maxVelocity: Double) {
        particles = (0..<populationSize).map { _ in Particle(dimensions: dimensions, maxVelocity: maxVelocity) }
        globalBest = Array(repeating: 0.0, count: dimensions)
    }

    func initializeGlobalBest(objectiveFunction: ([Double]) -> Double) {
        for particle in particles {
            particle.evaluate(objectiveFunction: objectiveFunction)
            if particle.bestFitness < globalBestFitness {
                globalBestFitness = particle.bestFitness
                globalBest = particle.bestPosition
            }
        }
    }

    func updateSwarm(w: Double, c1: Double, c2: Double, objectiveFunction: ([Double]) -> Double) {
        for particle in particles {
            particle.updateVelocity(globalBest: globalBest, w: w, c1: c1, c2: c2)
            particle.updatePosition()
            particle.evaluate(objectiveFunction: objectiveFunction)
            if particle.bestFitness < globalBestFitness {
                globalBestFitness = particle.bestFitness
                globalBest = particle.bestPosition
            }
        }
    }
}

func objectiveFunction(position: [Double]) -> Double {
    return position.reduce(0) { $0 + ($1 * $1) }
}

func optimize(dimensions: Int, populationSize: Int, maxVelocity: Double, w: Double, c1: Double, c2: Double, maxIterations: Int) -> Double {
    let swarm = Swarm(dimensions: dimensions, populationSize: populationSize, maxVelocity: maxVelocity)
    swarm.initializeGlobalBest(objectiveFunction: objectiveFunction)
    for _ in 0..<maxIterations {
        swarm.updateSwarm(w: w, c1: c1, c2: c2, objectiveFunction: objectiveFunction)
    }
    return swarm.globalBestFitness
}

func main() {
    let dimensions = 2
    let populationSize = 30
    let maxVelocity = 0.1
    let w = 0.729
    let c1 = 1.494
    let c2 = 1.494
    let maxIterations = 100
    let bestFitness = optimize(dimensions: dimensions, populationSize: populationSize, maxVelocity: maxVelocity, w: w, c1: c1, c2: c2, maxIterations: maxIterations)
    print("Best Fitness:", bestFitness)
}

main()