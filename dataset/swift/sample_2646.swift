swift
import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var searchSpace: (Double, Double)
    var particles: [Particle]
    var bestPosition: [Double]
    var bestScore: Double

    init(size: Int, dimensions: Int, searchSpace: (Double, Double)) {
        self.size = size
        self.dimensions = dimensions
        self.searchSpace = searchSpace
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions, searchSpace: searchSpace) }
        self.bestPosition = self.particles.randomElement()!.position
        self.bestScore = Double.infinity
    }

    func updateBestPosition() {
        for particle in particles {
            if particle.score < bestScore {
                bestScore = particle.score
                bestPosition = particle.position
            }
        }
    }

    func iterate() {
        for particle in particles {
            particle.updateVelocity(globalBest: bestPosition)
            particle.move()
            particle.evaluate()
        }
    }

    func run(iterations: Int) {
        for _ in 0..<iterations {
            iterate()
            updateBestPosition()
        }
    }
}

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int, searchSpace: (Double, Double)) {
        self.position = (0..<dimensions).map { _ in Double.random(in: searchSpace) }
        self.velocity = [Double](repeating: 0.0, count: dimensions)
        self.bestPosition = position
        self.bestScore = Double.infinity
    }

    func updateVelocity(globalBest: [Double]) {
        let inertia = 0.5
        let cognitiveFactor = 1.5
        let socialFactor = 1.5
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = cognitiveFactor * r1 * (bestPosition[i] - position[i])
            let social = socialFactor * r2 * (globalBest[i] - position[i])
            velocity[i] = inertia * velocity[i] + cognitive + social
        }
    }

    func move() {
        for i in 0..<position.count {
            position[i] += velocity[i]
        }
    }

    func evaluate() {
        score = objectiveFunction()
        if score < bestScore {
            bestScore = score
            bestPosition = position
        }
    }

    func objectiveFunction() -> Double {
        return position.map { $0 * $0 }.reduce(0, +)
    }
}

func main() {
    let swarmSize = 30
    let dimensions = 2
    let searchSpace: (Double, Double) = (-10, 10)
    let iterations = 100
    let swarm = Swarm(size: swarmSize, dimensions: dimensions, searchSpace: searchSpace)
    swarm.run(iterations: iterations)
    print("Best position: \(swarm.bestPosition)")
    print("Best score: \(swarm.bestScore)")
}

main()