import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int) {
        position = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        bestPosition = position
        bestScore = .infinity
    }

    func updateVelocity(globalBest: [Double], inertia: Double, cognitive: Double, social: Double) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            velocity[i] = inertia * velocity[i] + cognitive * r1 * (bestPosition[i] - position[i]) + social * r2 * (globalBest[i] - position[i])
        }
    }

    func updatePosition() {
        for i in 0..<position.count {
            position[i] += velocity[i]
        }
    }

    func evaluate(fitnessFunction: ([Double]) -> Double) {
        let score = fitnessFunction(position)
        if score < bestScore {
            bestScore = score
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    let fitnessFunction: ([Double]) -> Double
    let maxIterations: Int
    let inertia: Double
    let cognitive: Double
    let social: Double
    var globalBest: [Double]?
    var globalBestScore: Double

    init(size: Int, dimensions: Int, fitnessFunction: @escaping ([Double]) -> Double, maxIterations: Int, inertia: Double, cognitive: Double, social: Double) {
        particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
        self.fitnessFunction = fitnessFunction
        self.maxIterations = maxIterations
        self.inertia = inertia
        self.cognitive = cognitive
        self.social = social
        globalBest = nil
        globalBestScore = .infinity
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBestScore = particle.bestScore
                globalBest = particle.bestPosition
            }
        }
    }

    func optimize() {
        for _ in 0..<maxIterations {
            for particle in particles {
                particle.updateVelocity(globalBest: globalBest ?? [], inertia: inertia, cognitive: cognitive, social: social)
                particle.updatePosition()
                particle.evaluate(fitnessFunction: fitnessFunction)
            }
            updateGlobalBest()
        }
    }
}

func sphereFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let dimensions = 2
    let size = 30
    let maxIterations = 100
    let inertia = 0.5
    let cognitive = 1.5
    let social = 1.5
    let swarm = Swarm(size: size, dimensions: dimensions, fitnessFunction: sphereFunction, maxIterations: maxIterations, inertia: inertia, cognitive: cognitive, social: social)
    swarm.optimize()
    print("Best position:", swarm.globalBest ?? [])
    print("Best score:", swarm.globalBestScore)
}

main()