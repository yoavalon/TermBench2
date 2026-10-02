import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]

    init(dimensions: Int) {
        self.position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = position
    }

    func updateVelocity(globalBest: [Double], inertia: Double, cognitive: Double, social: Double) {
        for i in 0..<velocity.count {
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

    func updateBestPosition(objectiveFunction: ([Double]) -> Double) {
        let currentFitness = objectiveFunction(position)
        let bestFitness = objectiveFunction(bestPosition)
        if currentFitness < bestFitness {
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]
    let objectiveFunction: ([Double]) -> Double

    init(dimensions: Int, numParticles: Int, objectiveFunction: @escaping ([Double]) -> Double) {
        self.particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        self.globalBest = particles[0].position
        self.objectiveFunction = objectiveFunction
    }

    func updateGlobalBest() {
        for particle in particles {
            let currentFitness = objectiveFunction(particle.position)
            let globalBestFitness = objectiveFunction(globalBest)
            if currentFitness < globalBestFitness {
                globalBest = particle.position
            }
        }
    }

    func optimize(inertia: Double, cognitive: Double, social: Double) {
        while true {
            for particle in particles {
                particle.updateVelocity(globalBest: globalBest, inertia: inertia, cognitive: cognitive, social: social)
                particle.updatePosition()
                particle.updateBestPosition(objectiveFunction: objectiveFunction)
            }
            updateGlobalBest()
        }
    }
}

func objectiveFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + ($1 * $1) }
}

func main() {
    let dimensions = 2
    let numParticles = 30
    let inertia = 0.7
    let cognitive = 1.5
    let social = 1.5
    let swarm = Swarm(dimensions: dimensions, numParticles: numParticles, objectiveFunction: objectiveFunction)
    swarm.optimize(inertia: inertia, cognitive: cognitive, social: social)
}

main()