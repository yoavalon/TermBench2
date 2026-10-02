import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int) {
        self.position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestScore = .infinity
    }
}

class Swarm {
    var particles: [Particle]
    var gbestPosition: [Double]?
    var gbestScore: Double

    init(numParticles: Int, dimensions: Int) {
        self.particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        self.gbestScore = .infinity
    }

    func updateGbest() {
        for particle in particles {
            if particle.bestScore < gbestScore {
                gbestScore = particle.bestScore
                gbestPosition = particle.bestPosition
            }
        }
    }

    func updateParticles(w: Double, c1: Double, c2: Double) {
        for particle in particles {
            for i in 0..<particle.position.count {
                let r1 = Double.random(in: 0...1)
                let r2 = Double.random(in: 0...1)
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.bestPosition[i] - particle.position[i]) + c2 * r2 * (gbestPosition?[i] ?? 0 - particle.position[i])
                particle.position[i] += particle.velocity[i]
            }
        }
    }

    func evaluate(objectiveFunction: ([Double]) -> Double) {
        for particle in particles {
            let score = objectiveFunction(particle.position)
            if score < particle.bestScore {
                particle.bestScore = score
                particle.bestPosition = particle.position
            }
        }
    }
}

func objectiveFunction(_ x: [Double]) -> Double {
    return x.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let dimensions = 3
    let numParticles = 20
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let iterations = 100
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions)
    for _ in 0..<iterations {
        swarm.updateGbest()
        swarm.updateParticles(w: w, c1: c1, c2: c2)
        swarm.evaluate(objectiveFunction: objectiveFunction)
    }
    print("Best score:", swarm.gbestScore)
    print("Best position:", swarm.gbestPosition ?? [])
}

main()