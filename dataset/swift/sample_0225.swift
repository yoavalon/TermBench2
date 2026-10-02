import Foundation

class PSOSettings {
    var dimensions: Int
    var populationSize: Int
    var maxIterations: Int
    var c1: Double
    var c2: Double
    var w: Double

    init(dimensions: Int, populationSize: Int, maxIterations: Int) {
        self.dimensions = dimensions
        self.populationSize = populationSize
        self.maxIterations = maxIterations
        self.c1 = 2.0
        self.c2 = 2.0
        self.w = 0.7
    }
}

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double

    init(dimensions: Int, lowerBound: Double, upperBound: Double) {
        self.position = (0..<dimensions).map { _ in Double.random(in: lowerBound...upperBound) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestFitness = Double.greatestFiniteMagnitude
    }
}

func fitness(_ position: [Double]) -> Double {
    return position.reduce(0) { $0 + $1 * $1 }
}

func updateVelocity(_ particle: Particle, globalBest: [Double], settings: PSOSettings) {
    for i in 0..<settings.dimensions {
        let r1 = Double.random(in: 0...1)
        let r2 = Double.random(in: 0...1)
        let cognitive = settings.c1 * r1 * (particle.bestPosition[i] - particle.position[i])
        let social = settings.c2 * r2 * (globalBest[i] - particle.position[i])
        particle.velocity[i] = settings.w * particle.velocity[i] + cognitive + social
    }
}

func updatePosition(_ particle: Particle, settings: PSOSettings) {
    for i in 0..<settings.dimensions {
        particle.position[i] += particle.velocity[i]
        if particle.position[i] < -10 {
            particle.position[i] = -10
        } else if particle.position[i] > 10 {
            particle.position[i] = 10
        }
    }
}

func optimize(_ settings: PSOSettings) -> ([Double], Double) {
    var population = (0..<settings.populationSize).map { _ in Particle(dimensions: settings.dimensions, lowerBound: -10, upperBound: 10) }
    var globalBest = [Double](repeating: 0, count: settings.dimensions)
    var globalBestFitness = Double.greatestFiniteMagnitude
    for _ in 0..<settings.maxIterations {
        for particle in population {
            let currentFitness = fitness(particle.position)
            if currentFitness < particle.bestFitness {
                particle.bestFitness = currentFitness
                particle.bestPosition = particle.position
            }
            if currentFitness < globalBestFitness {
                globalBestFitness = currentFitness
                globalBest = particle.position
            }
        }
        for particle in population {
            updateVelocity(particle, globalBest: globalBest, settings: settings)
            updatePosition(particle, settings: settings)
        }
    }
    return (globalBest, globalBestFitness)
}

func main() {
    let settings = PSOSettings(dimensions: 2, populationSize: 30, maxIterations: 100)
    let (bestPosition, bestFitness) = optimize(settings)
    print("Best position:", bestPosition)
    print("Best fitness:", bestFitness)
}

main()