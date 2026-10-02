import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double

    init(dimensions: Int) {
        position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        bestPosition = position
        bestFitness = Double.infinity
    }

    func updateVelocity(globalBest: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<velocity.count {
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

    func evaluateFitness(fitnessFunction: ([Double]) -> Double) {
        bestFitness = fitnessFunction(position)
        if bestFitness < fitnessFunction(bestPosition) {
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBestPosition: [Double]?
    var globalBestFitness: Double

    init(dimensions: Int, numParticles: Int) {
        particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        globalBestPosition = nil
        globalBestFitness = Double.infinity
    }

    func updateGlobalBest(fitnessFunction: ([Double]) -> Double) {
        for particle in particles {
            particle.evaluateFitness(fitnessFunction: fitnessFunction)
            if particle.bestFitness < globalBestFitness {
                globalBestFitness = particle.bestFitness
                globalBestPosition = particle.bestPosition
            }
        }
    }

    func optimize(fitnessFunction: ([Double]) -> Double, w: Double, c1: Double, c2: Double, iterations: Int) {
        for _ in 0..<iterations {
            updateGlobalBest(fitnessFunction: fitnessFunction)
            for particle in particles {
                particle.updateVelocity(globalBest: globalBestPosition!, w: w, c1: c1, c2: c2)
                particle.updatePosition()
            }
        }
    }
}

func sphereFunction(_ x: [Double]) -> Double {
    return x.map { $0 * $0 }.reduce(0, +)
}

func main() {
    let dimensions = 3
    let numParticles = 10
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let iterations = 100
    let swarm = Swarm(dimensions: dimensions, numParticles: numParticles)
    swarm.optimize(fitnessFunction: sphereFunction, w: w, c1: c1, c2: c2, iterations: iterations)
    print("Global Best Position: \(swarm.globalBestPosition ?? [])")
    print("Global Best Fitness: \(swarm.globalBestFitness)")
}

main()