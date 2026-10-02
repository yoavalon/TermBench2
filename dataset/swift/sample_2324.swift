import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestFitness: Double

    init(dim: Int, lb: Double, ub: Double) {
        self.position = (0..<dim).map { _ in Double.random(in: lb...ub) }
        self.velocity = (0..<dim).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestFitness = .infinity
    }

    func updateVelocity(globalBest: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<velocity.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (globalBest[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition(lb: Double, ub: Double) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            if position[i] < lb {
                position[i] = lb
            }
            if position[i] > ub {
                position[i] = ub
            }
        }
    }
}

func fitnessFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + pow($1, 2) }
}

func optimize(dim: Int, lb: Double, ub: Double, numParticles: Int, w: Double, c1: Double, c2: Double, maxIter: Int) -> ([Double], Double) {
    var particles = (0..<numParticles).map { _ in Particle(dim: dim, lb: lb, ub: ub) }
    var globalBest = [Double](repeating: .infinity, count: dim)
    var globalBestFitness = .infinity

    for _ in 0..<maxIter {
        for particle in particles {
            let currentFitness = fitnessFunction(x: particle.position)
            if currentFitness < particle.bestFitness {
                particle.bestFitness = currentFitness
                particle.bestPosition = particle.position
            }
            if currentFitness < globalBestFitness {
                globalBestFitness = currentFitness
                globalBest = particle.position
            }
        }
        for particle in particles {
            particle.updateVelocity(globalBest: globalBest, w: w, c1: c1, c2: c2)
            particle.updatePosition(lb: lb, ub: ub)
        }
    }
    return (globalBest, globalBestFitness)
}

func main() {
    let dim = 30
    let lb = -100.0, ub = 100.0
    let numParticles = 50
    let w = 0.7, c1 = 1.5, c2 = 1.5
    let maxIter = 10000

    let (bestPosition, bestFitness) = optimize(dim: dim, lb: lb, ub: ub, numParticles: numParticles, w: w, c1: c1, c2: c2, maxIter: maxIter)
    print("Best position:", bestPosition)
    print("Best fitness:", bestFitness)
}

main()