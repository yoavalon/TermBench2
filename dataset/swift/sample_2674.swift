import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var particles: [Particle]
    var bestPosition: [Double]?
    var bestValue: Double = .infinity

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
        self.bestPosition = nil
        self.bestValue = .infinity
    }

    func updateBest() {
        for particle in particles {
            if particle.value < bestValue {
                bestValue = particle.value
                bestPosition = particle.position.map { $0 }
            }
        }
    }

    func optimize(iterations: Int) {
        for _ in 0..<iterations {
            for particle in particles {
                particle.update(globalBest: bestPosition ?? [])
            }
            updateBest()
        }
    }
}

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestValue: Double

    init(dimensions: Int) {
        self.position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = position.map { $0 }
        self.bestValue = calculateValue()
    }

    func calculateValue() -> Double {
        return position.reduce(0) { $0 + ($1 * $1) }
    }

    func update(globalBest: [Double]) {
        let w = 0.7
        let c1 = 1.5
        let c2 = 1.5
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            velocity[i] = w * velocity[i] + c1 * r1 * (bestPosition[i] - position[i]) + c2 * r2 * (globalBest[i] - position[i])
            position[i] += velocity[i]
        }
        bestValue = calculateValue()
        if bestValue < bestValue {
            bestValue = bestValue
            bestPosition = position.map { $0 }
        }
    }
}

func main() {
    let dimensions = 2
    let swarmSize = 30
    let iterations = 100
    let swarm = Swarm(size: swarmSize, dimensions: dimensions)
    swarm.optimize(iterations: iterations)
    print("Best position:", swarm.bestPosition ?? [])
    print("Best value:", swarm.bestValue)
}

main()