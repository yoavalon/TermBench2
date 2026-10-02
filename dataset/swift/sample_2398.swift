swift
import Foundation

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

    func updateVelocity(globalBestPosition: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitiveVelocity = c1 * r1 * (bestPosition[i] - position[i])
            let socialVelocity = c2 * r2 * (globalBestPosition[i] - position[i])
            velocity[i] = w * velocity[i] + cognitiveVelocity + socialVelocity
        }
    }

    func updatePosition(lowerBound: Double, upperBound: Double) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(lowerBound, min(upperBound, position[i]))
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBestPosition: [Double]
    var globalBestFitness: Double

    init(numParticles: Int, dimensions: Int, lowerBound: Double, upperBound: Double) {
        self.particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions, lowerBound: lowerBound, upperBound: upperBound) }
        self.globalBestPosition = (0..<dimensions).map { _ in Double.random(in: lowerBound...upperBound) }
        self.globalBestFitness = Double.greatestFiniteMagnitude
    }

    func evaluateFitness(objectiveFunction: (Particle) -> Double) {
        for particle in particles {
            let fitness = objectiveFunction(particle)
            if fitness < particle.bestFitness {
                particle.bestFitness = fitness
                particle.bestPosition = particle.position
            }
            if fitness < globalBestFitness {
                globalBestFitness = fitness
                globalBestPosition = particle.position
            }
        }
    }

    func updateParticles(w: Double, c1: Double, c2: Double) {
        for particle in particles {
            particle.updateVelocity(globalBestPosition: globalBestPosition, w: w, c1: c1, c2: c2)
            particle.updatePosition(lowerBound: -10, upperBound: 10)
        }
    }
}

func objectiveFunction(x: [Double]) -> Double {
    return x.enumerated().reduce(0) { $0 + sin($1.element) * sin($1.element + Double($1.offset + 1) * .pi / Double(x.count)) }
}

func main() {
    let numParticles = 30
    let dimensions = 30
    let lowerBound = -10
    let upperBound = 10
    let w = 0.729
    let c1 = 1.494
    let c2 = 1.494
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions, lowerBound: lowerBound, upperBound: upperBound)
    while true {
        swarm.evaluateFitness(objectiveFunction: objectiveFunction)
        swarm.updateParticles(w: w, c1: c1, c2: c2)
    }
}

main()