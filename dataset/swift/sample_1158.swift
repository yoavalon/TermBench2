class Particle {
    var position: Double
    var velocity: Double
    var bestPosition: Double

    init(position: Double, velocity: Double, bestPosition: Double) {
        self.position = position
        self.velocity = velocity
        self.bestPosition = bestPosition
    }

    func updateVelocity(globalBest: Double, w: Double, c1: Double, c2: Double) {
        let r1 = 0.5
        let r2 = 0.3
        let newVelocity = w * velocity + c1 * r1 * (bestPosition - position) + c2 * r2 * (globalBest - position)
        self.velocity = newVelocity
    }

    func updatePosition() {
        self.position += velocity
        if self.position < self.bestPosition {
            self.bestPosition = self.position
        }
    }
}

func updateGlobalBest(particles: [Particle]) -> Double {
    var best = particles[0].bestPosition
    for particle in particles {
        if particle.bestPosition < best {
            best = particle.bestPosition
        }
    }
    return best
}

func optimize(particles: [Particle], globalBest: Double, w: Double, c1: Double, c2: Double, iterations: Int) -> Double {
    if iterations == 0 {
        return globalBest
    }
    for particle in particles {
        particle.updateVelocity(globalBest: globalBest, w: w, c1: c1, c2: c2)
        particle.updatePosition()
    }
    let newGlobalBest = updateGlobalBest(particles: particles)
    return optimize(particles: particles, globalBest: newGlobalBest, w: w, c1: c1, c2: c2, iterations: iterations - 1)
}

func main() {
    let numParticles = 10
    let initialPositions = [Double](repeating: 0.0, count: numParticles)
    let initialVelocities = [Double](repeating: 0.1, count: numParticles)
    let bestPositions = [Double](repeating: 0.0, count: numParticles)
    let particles = (0..<numParticles).map { i in
        Particle(position: initialPositions[i], velocity: initialVelocities[i], bestPosition: bestPositions[i])
    }
    let globalBest = updateGlobalBest(particles: particles)
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let iterations = Int.max
    optimize(particles: particles, globalBest: globalBest, w: w, c1: c1, c2: c2, iterations: iterations)
}

main()