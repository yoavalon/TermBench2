import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var bounds: [Double]
    var particles: [Particle]
    var gbest: Particle?

    init(size: Int, dimensions: Int, bounds: [Double]) {
        self.size = size
        self.dimensions = dimensions
        self.bounds = bounds
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions, bounds: bounds) }
        self.gbest = nil
    }

    func updateGbest() {
        for particle in particles {
            if gbest == nil || particle.fitness < gbest!.fitness {
                gbest = particle
            }
        }
    }

    func updateParticles() {
        for particle in particles {
            particle.updateVelocity(gbest: gbest!)
            particle.updatePosition()
        }
    }
}

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var fitness: Double

    init(dimensions: Int, bounds: [Double]) {
        self.position = (0..<dimensions).map { _ in Double.random(in: bounds[0]...bounds[1]) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = position
        self.fitness = .infinity
    }

    func updateVelocity(gbest: Particle) {
        let w: Double = 0.5
        let c1: Double = 1.5
        let c2: Double = 1.5
        for i in 0..<velocity.count {
            let r1: Double = Double.random(in: 0...1)
            let r2: Double = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (gbest.position[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition() {
        for i in 0..<position.count {
            position[i] += velocity[i]
            if position[i] < bounds[0] {
                position[i] = bounds[0]
            }
            if position[i] > bounds[1] {
                position[i] = bounds[1]
            }
        }
    }
}

func objectiveFunction(x: [Double]) -> Double {
    return x.map { $0 * $0 }.reduce(0, +)
}

func optimize(swarm: Swarm, maxIterations: Int) {
    for _ in 0..<maxIterations {
        swarm.updateGbest()
        for particle in swarm.particles {
            particle.fitness = objectiveFunction(x: particle.position)
        }
        swarm.updateParticles()
    }
}

func main() {
    let size = 30
    let dimensions = 2
    let bounds = [-10, 10]
    let maxIterations = 100
    let swarm = Swarm(size: size, dimensions: dimensions, bounds: bounds)
    optimize(swarm: swarm, maxIterations: maxIterations)
    print(swarm.gbest!.position)
}

main()