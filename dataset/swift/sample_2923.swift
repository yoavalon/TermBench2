import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double

    init(dimensions: Int) {
        self.position = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestFitness = .greatestFiniteMagnitude
    }
}

class PSO {
    let dimensions: Int
    var population: [Particle]
    var gbestPosition: [Double]
    var gbestFitness: Double
    let omega: Double
    let phiP: Double
    let phiG: Double

    init(dimensions: Int, populationSize: Int, omega: Double, phiP: Double, phiG: Double) {
        self.dimensions = dimensions
        self.population = (0..<populationSize).map { _ in Particle(dimensions: dimensions) }
        self.gbestPosition = Array(repeating: 0.0, count: dimensions)
        self.gbestFitness = .greatestFiniteMagnitude
        self.omega = omega
        self.phiP = phiP
        self.phiG = phiG
    }

    func updateGlobalBest() {
        for particle in population {
            let fitness = fitness(position: particle.position)
            if fitness < particle.bestFitness {
                particle.bestFitness = fitness
                particle.bestPosition = particle.position
            }
            if fitness < gbestFitness {
                gbestFitness = fitness
                gbestPosition = particle.position
            }
        }
    }

    func updateVelocity(particle: Particle) {
        for i in 0..<dimensions {
            let rP = Double.random(in: 0...1)
            let rG = Double.random(in: 0...1)
            let cognitive = phiP * rP * (particle.bestPosition[i] - particle.position[i])
            let social = phiG * rG * (gbestPosition[i] - particle.position[i])
            particle.velocity[i] = omega * particle.velocity[i] + cognitive + social
        }
    }

    func updatePosition(particle: Particle) {
        for i in 0..<dimensions {
            particle.position[i] += particle.velocity[i]
        }
    }

    func fitness(position: [Double]) -> Double {
        return position.map { $0 * $0 }.reduce(0, +)
    }

    func run() {
        while true {
            updateGlobalBest()
            for particle in population {
                updateVelocity(particle: particle)
                updatePosition(particle: particle)
            }
        }
    }
}

func main() {
    let dimensions = 2
    let populationSize = 10
    let omega = 0.7
    let phiP = 1.5
    let phiG = 1.5
    let pso = PSO(dimensions: dimensions, populationSize: populationSize, omega: omega, phiP: phiP, phiG: phiG)
    pso.run()
}

main()