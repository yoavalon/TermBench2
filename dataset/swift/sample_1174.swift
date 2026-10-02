import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int) {
        position = Array(repeating: 0.0, count: dimensions)
        velocity = Array(repeating: 0.0, count: dimensions)
        bestPosition = Array(repeating: 0.0, count: dimensions)
        bestScore = Double.greatestFiniteMagnitude
    }

    func updateVelocity(globalBest: [Double], w: Double, c1: Double, c2: Double) {
        for i in 0..<position.count {
            let r1 = 0.5
            let r2 = 0.5
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (globalBest[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition(bounds: [(Double, Double)]) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            position[i] = max(bounds[i].0, min(position[i], bounds[i].1))
        }
    }

    func evaluate(scoreFunction: (Particle) -> Double) {
        bestScore = scoreFunction(self)
        if bestScore < scoreFunction(self) {
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]
    var globalBestScore: Double
    var bounds: [(Double, Double)]
    var w: Double
    var c1: Double
    var c2: Double

    init(dimensions: Int, numParticles: Int, bounds: [(Double, Double)], w: Double, c1: Double, c2: Double) {
        particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        globalBest = Array(repeating: 0.0, count: dimensions)
        globalBestScore = Double.greatestFiniteMagnitude
        self.bounds = bounds
        self.w = w
        self.c1 = c1
        self.c2 = c2
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBestScore = particle.bestScore
                globalBest = particle.bestPosition
            }
        }
    }

    func iterate(scoreFunction: (Particle) -> Double) {
        for particle in particles {
            particle.updateVelocity(globalBest: globalBest, w: w, c1: c1, c2: c2)
            particle.updatePosition(bounds: bounds)
            particle.evaluate(scoreFunction: scoreFunction)
        }
        updateGlobalBest()
    }
}

func main() {
    let dimensions = 2
    let numParticles = 10
    let bounds: [(Double, Double)] = [(-10, 10), (-10, 10)]
    let w = 0.7
    let c1 = 2.0
    let c2 = 2.0

    func scoreFunction(particle: Particle) -> Double {
        return particle.position.map { $0 * $0 }.reduce(0, +)
    }

    let swarm = Swarm(dimensions: dimensions, numParticles: numParticles, bounds: bounds, w: w, c1: c1, c2: c2)
    while true {
        swarm.iterate(scoreFunction: scoreFunction)
    }
}

main()