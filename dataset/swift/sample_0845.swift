import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int, bounds: (Double, Double)) {
        position = (0..<dimensions).map { _ in bounds.0 + (bounds.1 - bounds.0) * Double.random(in: 0...1) }
        velocity = Array(repeating: 0.0, count: dimensions)
        bestPosition = position
        bestScore = .greatestFiniteMagnitude
    }
}

class Swarm {
    var particles: [Particle]
    var bounds: (Double, Double)
    var function: (Particle) -> Double
    var w: Double
    var c1: Double
    var c2: Double
    var bestSwarmPosition: [Double]
    var bestSwarmScore: Double

    init(particles: [Particle], bounds: (Double, Double), function: @escaping (Particle) -> Double, w: Double, c1: Double, c2: Double) {
        self.particles = particles
        self.bounds = bounds
        self.function = function
        self.w = w
        self.c1 = c1
        self.c2 = c2
        bestSwarmPosition = Array(repeating: 0.0, count: bounds.0.distance(to: bounds.1))
        bestSwarmScore = .greatestFiniteMagnitude
    }

    func evaluate() {
        for particle in particles {
            let score = function(particle)
            if score < particle.bestScore {
                particle.bestScore = score
                particle.bestPosition = particle.position
            }
            if score < bestSwarmScore {
                bestSwarmScore = score
                bestSwarmPosition = particle.position
            }
        }
    }

    func update() {
        for particle in particles {
            for i in 0..<particle.position.count {
                let r1 = Double.random(in: 0...1)
                let r2 = Double.random(in: 0...1)
                let velocityCognitive = c1 * r1 * (particle.bestPosition[i] - particle.position[i])
                let velocitySocial = c2 * r2 * (bestSwarmPosition[i] - particle.position[i])
                particle.velocity[i] = w * particle.velocity[i] + velocityCognitive + velocitySocial
                particle.position[i] += particle.velocity[i]
                particle.position[i] = max(bounds.0, min(bounds.1, particle.position[i]))
            }
        }
    }
}

func objectiveFunction(particle: Particle) -> Double {
    return particle.position.reduce(0) { $0 + $1 * $1 }
}

func optimize(dimensions: Int, bounds: (Double, Double), numParticles: Int, maxIterations: Int, w: Double, c1: Double, c2: Double) -> ([Double], Double) {
    let particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions, bounds: bounds) }
    let swarm = Swarm(particles: particles, bounds: bounds, function: objectiveFunction, w: w, c1: c1, c2: c2)
    for _ in 0..<maxIterations {
        swarm.evaluate()
        swarm.update()
    }
    return (swarm.bestSwarmPosition, swarm.bestSwarmScore)
}

func main() {
    let dimensions = 2
    let bounds: (Double, Double) = (-10, 10)
    let numParticles = 30
    let maxIterations = 100
    let w = 0.729
    let c1 = 1.494
    let c2 = 1.494
    let result = optimize(dimensions: dimensions, bounds: bounds, numParticles: numParticles, maxIterations: maxIterations, w: w, c1: c1, c2: c2)
    print("Best position:", result.0)
    print("Best score:", result.1)
}

main()