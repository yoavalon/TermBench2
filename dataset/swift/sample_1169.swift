swift
class Swarm {
    var particles: [Particle]
    var gbest: Particle

    init(size: Int, dimensions: Int) {
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
        self.gbest = self.particles[0]
    }

    func update_gbest() {
        for particle in particles {
            if particle.fitness < gbest.fitness {
                gbest = particle
            }
        }
    }

    func optimize() {
        while true {
            for particle in particles {
                particle.update_velocity(gbest: gbest)
                particle.update_position()
            }
            update_gbest()
        }
    }
}

class Particle {
    var position: [Double]
    var velocity: [Double]
    var best_position: [Double]
    var fitness: Double

    init(dimensions: Int) {
        self.position = [Double](repeating: 0.0, count: dimensions)
        self.velocity = [Double](repeating: 0.0, count: dimensions)
        self.best_position = self.position
        self.fitness = Double.greatestFiniteMagnitude
    }

    func update_velocity(gbest: Particle) {
        for i in 0..<position.count {
            let r1 = 0.5
            let r2 = 0.5
            let inertia = 0.7
            velocity[i] = inertia * velocity[i] + r1 * (best_position[i] - position[i]) + r2 * (gbest.position[i] - position[i])
        }
    }

    func update_position() {
        for i in 0..<position.count {
            position[i] += velocity[i]
            if fitness > calculate_fitness() {
                best_position = position
                fitness = calculate_fitness()
            }
        }
    }

    func calculate_fitness() -> Double {
        return position.reduce(0) { $0 + $1 * $1 }
    }
}

func main() {
    let swarm = Swarm(size: 10, dimensions: 2)
    swarm.optimize()
}

main()