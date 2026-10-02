import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var searchSpace: (Double, Double)
    var particles: [Particle]

    init(size: Int, dimensions: Int, searchSpace: (Double, Double)) {
        self.size = size
        self.dimensions = dimensions
        self.searchSpace = searchSpace
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions, searchSpace: searchSpace) }
    }

    func update() {
        for particle in particles {
            particle.updateVelocity()
            particle.updatePosition()
        }
    }
}

class Particle {
    var dimensions: Int
    var searchSpace: (Double, Double)
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double

    init(dimensions: Int, searchSpace: (Double, Double)) {
        self.dimensions = dimensions
        self.searchSpace = searchSpace
        self.position = (0..<dimensions).map { _ in Double.random(in: searchSpace.0...searchSpace.1) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = position
        self.bestFitness = Double.greatestFiniteMagnitude
    }

    func updateVelocity() {
        let w = 0.7
        let c1 = 1.5
        let c2 = 1.5
        for i in 0..<dimensions {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (bestPosition[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition() {
        for i in 0..<dimensions {
            position[i] += velocity[i]
            position[i] = max(searchSpace.0, min(searchSpace.1, position[i]))
        }
    }
}

func fitnessFunction(position: [Double]) -> Double {
    return position.reduce(0) { $0 + ($1 * $1) }
}

func optimize(swarm: Swarm, maxIterations: Int) {
    for iteration in 0..<maxIterations {
        for particle in swarm.particles {
            let currentFitness = fitnessFunction(position: particle.position)
            if currentFitness < particle.bestFitness {
                particle.bestFitness = currentFitness
                particle.bestPosition = particle.position
            }
        }
        swarm.update()
    }
}

func main() {
    let size = 30
    let dimensions = 2
    let searchSpace = (-10.0, 10.0)
    let maxIterations = 100
    let swarm = Swarm(size: size, dimensions: dimensions, searchSpace: searchSpace)
    optimize(swarm: swarm, maxIterations: maxIterations)
}

main()