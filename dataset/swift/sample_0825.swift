class Particle {
    var position: [Double]
    var velocity: [Double]
    var fitness: Double = 0.0
    var bestPosition: [Double] = []

    init(dimensions: Int) {
        self.position = [Double](repeating: 0.0, count: dimensions)
        self.velocity = [Double](repeating: 0.0, count: dimensions)
    }

    func updateVelocity(bestPosition: [Double]) {
        let w: Double = 0.7
        let c1: Double = 1.5
        let c2: Double = 1.5
        let r1: Double = 0.5
        let r2: Double = 0.5

        for i in 0..<position.count {
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (self.bestPosition[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition() {
        for i in 0..<position.count {
            position[i] += velocity[i]
        }
        fitness = calculateFitness()
    }

    func calculateFitness() -> Double {
        return position.reduce(0) { $0 + ($1 * $1) }
    }
}

class Swarm {
    var particles: [Particle]
    var bestPosition: [Double]?

    init(size: Int, dimensions: Int) {
        particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
    }

    func updateBestPosition() {
        if bestPosition == nil {
            bestPosition = particles[0].position
        } else {
            for particle in particles {
                if particle.fitness > bestPosition!.reduce(0) { $0 + ($1 * $1) } {
                    bestPosition = particle.position
                }
            }
        }
    }

    func updateParticles(iterations: Int) {
        if iterations > 0 {
            for particle in particles {
                particle.updateVelocity(bestPosition: bestPosition!)
                particle.updatePosition()
            }
            updateBestPosition()
            updateParticles(iterations: iterations - 1)
        }
    }
}

func optimize(swarm: Swarm, iterations: Int) {
    swarm.updateParticles(iterations: iterations)
}

func main() {
    let dimensions = 2
    let swarmSize = 10
    let iterations = 50
    let swarm = Swarm(size: swarmSize, dimensions: dimensions)
    optimize(swarm: swarm, iterations: iterations)
}

main()