import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double = .infinity

    init(dimensions: Int, bounds: [(Double, Double)]) {
        self.position = (0..<dimensions).map { _ in Double.random(in: bounds[$0].0...bounds[$0].1) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
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

    func updatePosition(bounds: [(Double, Double)]) {
        for i in 0..<position.count {
            position[i] = position[i] + velocity[i]
            position[i] = max(bounds[i].0, min(position[i], bounds[i].1))
        }
    }

    func evaluate(fitnessFunction: ([Double]) -> Double) {
        let fitness = fitnessFunction(position)
        bestFitness = min(bestFitness, fitness)
    }
}

func optimize(fitnessFunction: ([Double]) -> Double, dimensions: Int, bounds: [(Double, Double)], numParticles: Int, w: Double, c1: Double, c2: Double, maxIterations: Int) -> ([Double], Double) {
    var particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions, bounds: bounds) }
    var globalBest = [Double](repeating: .infinity, count: dimensions)
    var globalBestFitness = .infinity

    for _ in 0..<maxIterations {
        for particle in particles {
            particle.evaluate(fitnessFunction: fitnessFunction)
            if particle.bestFitness < globalBestFitness {
                globalBestFitness = particle.bestFitness
                globalBest = particle.bestPosition
            }
        }
        for particle in particles {
            particle.updateVelocity(globalBest: globalBest, w: w, c1: c1, c2: c2)
            particle.updatePosition(bounds: bounds)
        }
    }

    return (globalBest, globalBestFitness)
}

func main() {
    func sphereFunction(x: [Double]) -> Double {
        return x.reduce(0) { $0 + ($1 * $1) }
    }

    let dimensions = 3
    let bounds = [(Double, Double)](repeating: (-5.12, 5.12), count: dimensions)
    let numParticles = 30
    let w = 0.729
    let c1 = 1.494
    let c2 = 1.494
    let maxIterations = 100

    let (bestPosition, bestFitness) = optimize(fitnessFunction: sphereFunction, dimensions: dimensions, bounds: bounds, numParticles: numParticles, w: w, c1: c1, c2: c2, maxIterations: maxIterations)
    print("Best position: \(bestPosition)")
    print("Best fitness: \(bestFitness)")
}

main()