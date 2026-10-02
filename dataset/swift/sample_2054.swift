import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestValue: Double

    init(dimensions: Int) {
        position = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        bestPosition = position
        bestValue = .greatestFiniteMagnitude
    }

    func updateVelocity(globalBest: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
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
        }
    }

    func evaluate(objectiveFunction: (inout [Double]) -> Double) {
        bestValue = objectiveFunction(&position)
        if bestValue < bestValue {
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]
    var globalBestValue: Double

    init(dimensions: Int, numParticles: Int) {
        particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        globalBest = (0..<dimensions).map { _ in .greatestFiniteMagnitude }
        globalBestValue = .greatestFiniteMagnitude
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestValue < globalBestValue {
                globalBestValue = particle.bestValue
                globalBest = particle.bestPosition
            }
        }
    }

    func iterate(objectiveFunction: (inout [Double]) -> Double) {
        for particle in particles {
            particle.updateVelocity(globalBest: globalBest)
            particle.updatePosition()
            particle.evaluate(objectiveFunction: objectiveFunction)
        }
        updateGlobalBest()
    }
}

func objectiveFunction(_ x: inout [Double]) -> Double {
    return x.map { $0 * $0 }.reduce(0, +)
}

func optimize(dimensions: Int, numParticles: Int, maxIterations: Int) -> [Double] {
    let swarm = Swarm(dimensions: dimensions, numParticles: numParticles)
    for _ in 0..<maxIterations {
        swarm.iterate(objectiveFunction: objectiveFunction)
    }
    return swarm.globalBest
}

func main() {
    let dimensions = 10
    let numParticles = 20
    let maxIterations = 100
    let bestSolution = optimize(dimensions: dimensions, numParticles: numParticles, maxIterations: maxIterations)
    print("Best solution:", bestSolution)
}

main()