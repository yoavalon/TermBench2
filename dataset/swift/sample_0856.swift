import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int, bounds: [[Double]]) {
        position = (0..<dimensions).map { _ in Double.random(in: bounds[$0][0]...bounds[$0][1]) }
        velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        bestPosition = position
        bestScore = .infinity
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

    func updatePosition(bounds: [[Double]]) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(bounds[i][0], min(bounds[i][1], position[i]))
        }
    }
}

class Swarm {
    var particles: [Particle]
    var bestPosition: [Double]?
    var bestScore: Double
    var function: ([Double]) -> Double

    init(numParticles: Int, dimensions: Int, bounds: [[Double]], function: @escaping ([Double]) -> Double) {
        particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions, bounds: bounds) }
        bestPosition = nil
        bestScore = .infinity
        self.function = function
    }

    func optimize(maxIterations: Int, w: Double, c1: Double, c2: Double) {
        for _ in 0..<maxIterations {
            for particle in particles {
                let score = function(particle.position)
                if score < particle.bestScore {
                    particle.bestScore = score
                    particle.bestPosition = particle.position
                }
                if score < bestScore {
                    bestScore = score
                    bestPosition = particle.position
                }
            }
            for particle in particles {
                particle.updateVelocity(globalBest: bestPosition!, w: w, c1: c1, c2: c2)
                particle.updatePosition(bounds: bounds)
            }
        }
    }
}

func objectiveFunction(_ x: [Double]) -> Double {
    return x.reduce(0) { $0 + pow($1 - 2, 2) }
}

func main() {
    let dimensions = 3
    let bounds = (0..<dimensions).map { _ in [-10.0, 10.0] }
    let numParticles = 20
    let maxIterations = 100
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions, bounds: bounds, function: objectiveFunction)
    swarm.optimize(maxIterations: maxIterations, w: w, c1: c1, c2: c2)
    print(swarm.bestPosition!, swarm.bestScore)
}

main()