import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var best_pos: [Double]
    var best_score: Double

    init(dim: Int) {
        self.position = [Double](repeating: 0.0, count: dim)
        self.velocity = [Double](repeating: 0.0, count: dim)
        self.best_pos = [Double](repeating: 0.0, count: dim)
        self.best_score = Double.greatestFiniteMagnitude
    }

    func update_velocity(global_best: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_pos[i] - self.position[i]) + c2 * r2 * (global_best[i] - self.position[i])
        }
    }

    func update_position(bounds: ([Double], [Double])) {
        for i in 0..<position.count {
            self.position[i] += self.velocity[i]
            self.position[i] = max(bounds.0[i], min(bounds.1[i], self.position[i]))
        }
    }
}

class Swarm {
    var particles: [Particle]
    var best_global_pos: [Double]
    var best_global_score: Double

    init(num_particles: Int, dim: Int, bounds: ([Double], [Double])) {
        self.particles = (0..<num_particles).map { _ in Particle(dim: dim) }
        self.best_global_pos = [Double](repeating: 0.0, count: dim)
        self.best_global_score = Double.greatestFiniteMagnitude
    }

    func update_global_best() {
        for particle in particles {
            if particle.best_score < self.best_global_score {
                self.best_global_score = particle.best_score
                self.best_global_pos = particle.best_pos
            }
        }
    }

    func optimize(fitness_func: ([Double]) -> Double, max_iter: Int, w: Double, c1: Double, c2: Double) {
        for _ in 0..<max_iter {
            for particle in particles {
                particle.update_velocity(global_best: self.best_global_pos, w: w, c1: c1, c2: c2)
                particle.update_position(bounds: bounds)
                let score = fitness_func(particle.position)
                if score < particle.best_score {
                    particle.best_score = score
                    particle.best_pos = particle.position
                }
            }
            self.update_global_best()
        }
    }
}

func fitness_function(position: [Double]) -> Double {
    return position.reduce(0) { $0 + pow($1, 2) }
}

func main() {
    let num_particles = 30
    let dim = 2
    let bounds: ([Double], [Double]) = ([0.0] * dim, [10.0] * dim)
    let max_iter = 100
    let w = 0.7
    let c1 = 2.0
    let c2 = 2.0
    let swarm = Swarm(num_particles: num_particles, dim: dim, bounds: bounds)
    swarm.optimize(fitness_func: fitness_function, max_iter: max_iter, w: w, c1: c1, c2: c2)
    print(swarm.best_global_pos, swarm.best_global_score)
}

main()