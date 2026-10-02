swift
import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double

    init(dim: Int) {
        position = (0..<dim).map { _ in Double.random(in: -10...10) }
        velocity = (0..<dim).map { _ in Double.random(in: -1...1) }
        bestPosition = position
        bestFitness = Double.greatestFiniteMagnitude
    }

    func updateVelocity(globalBest: [Double], w: Double = 0.5, c1: Double = 1.5, c2: Double = 1.5) {
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
}

class Swarm {
    var particles: [Particle]
    var globalBestPosition: [Double]
    var globalBestFitness: Double

    init(dim: Int, numParticles: Int) {
        particles = (0..<numParticles).map { _ in Particle(dim: dim) }
        globalBestPosition = (0..<dim).map { _ in Double.greatestFiniteMagnitude }
        globalBestFitness = Double.greatestFiniteMagnitude
    }

    func updateGlobalBest() {
        for particle in particles {
            let fitness = evaluate(position: particle.position)
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

    func evaluate(position: [Double]) -> Double {
        return position.reduce(0) { $0 + ($1 * $1) }
    }

    func iterate() {
        updateGlobalBest()
        for particle in particles {
            particle.updateVelocity(globalBest: globalBestPosition)
            particle.updatePosition()
        }
    }
}

func main() {
    let dim = 2
    let numParticles = 10
    let swarm = Swarm(dim: dim, numParticles: numParticles)
    while true {
        swarm.iterate()
    }
}

main()