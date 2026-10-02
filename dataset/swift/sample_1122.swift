swift
class Swarm {
    var particles: [Particle]
    var best: Particle

    init(size: Int, dimensions: Int) {
        particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
        best = particles[0]
    }

    func updateBest() {
        for particle in particles {
            if particle.position < best.position {
                best = particle
            }
        }
    }

    func updatePositions() {
        for particle in particles {
            particle.updateVelocity(best: best)
            particle.move()
        }
    }
}

class Particle {
    var position: [Double]
    var velocity: [Double]
    var best: [Double]

    init(dimensions: Int) {
        position = [Double](repeating: 0.0, count: dimensions)
        velocity = [Double](repeating: 0.0, count: dimensions)
        best = position
    }

    func updateVelocity(best: Particle) {
        for i in 0..<position.count {
            let c1 = 1.5
            let c2 = 1.5
            let r1 = 0.5
            let r2 = 0.5
            velocity[i] = 0.7 * velocity[i] + c1 * r1 * (best.position[i] - position[i]) + c2 * r2 * (best[i] - position[i])
        }
    }

    func move() {
        for i in 0..<position.count {
            position[i] += velocity[i]
        }
        if position < best {
            best = position
        }
    }
}

func optimize(swarm: Swarm) {
    swarm.updatePositions()
    swarm.updateBest()
    optimize(swarm: swarm)
}

func main() {
    let swarm = Swarm(size: 10, dimensions: 2)
    optimize(swarm: swarm)
}

main()