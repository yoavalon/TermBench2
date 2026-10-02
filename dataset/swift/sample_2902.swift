import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double

    init(dimensions: Int) {
        self.position = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = position
        self.bestFitness = Double.greatestFiniteMagnitude
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

    func updatePosition(bounds: ([Double], [Double])) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(bounds.0[i], min(bounds.1[i], position[i]))
        }
    }

    func evaluateFitness(fitnessFunction: ([Double]) -> Double) {
        let fitness = fitnessFunction(position)
        if fitness < bestFitness {
            bestFitness = fitness
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]
    var globalBestFitness: Double
    var fitnessFunction: ([Double]) -> Double
    var bounds: ([Double], [Double])

    init(numParticles: Int, dimensions: Int, bounds: ([Double], [Double]), fitnessFunction: @escaping ([Double]) -> Double) {
        self.particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        self.globalBest = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.globalBestFitness = Double.greatestFiniteMagnitude
        self.fitnessFunction = fitnessFunction
        self.bounds = bounds
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestFitness < globalBestFitness {
                globalBestFitness = particle.bestFitness
                globalBest = particle.bestPosition
            }
        }
    }

    func optimize(w: Double, c1: Double, c2: Double) {
        while true {
            for particle in particles {
                particle.updateVelocity(globalBest: globalBest, w: w, c1: c1, c2: c2)
                particle.updatePosition(bounds: bounds)
                particle.evaluateFitness(fitnessFunction: fitnessFunction)
            }
            updateGlobalBest()
        }
    }
}

func fitnessFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + pow($1, 2) }
}

func main() {
    let dimensions = 2
    let numParticles = 30
    let bounds: ([Double], [Double]) = ([-10, -10], [10, 10])
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions, bounds: bounds, fitnessFunction: fitnessFunction)
    let w = 0.729
    let c1 = 1.494
    let c2 = 1.494
    swarm.optimize(w: w, c1: c1, c2: c2)
}

main()