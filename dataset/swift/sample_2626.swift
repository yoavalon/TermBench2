import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int, position: [Double]? = nil) {
        self.position = position ?? (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestScore = .infinity
    }

    func updateVelocity(globalBest: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (bestPosition[i] - position[i])
            let social = c2 * r2 * (globalBest[i] - position[i])
            velocity[i] = w * velocity[i] + cognitive + social
        }
    }

    func updatePosition(bounds: (Double, Double)?) {
        for i in 0..<position.count {
            position[i] += velocity[i]
            if let (minBound, maxBound) = bounds {
                position[i] = max(minBound, min(maxBound, position[i]))
            }
        }
    }

    func evaluate(function: ([Double]) -> Double) {
        let currentScore = function(position)
        if currentScore < bestScore {
            bestScore = currentScore
            bestPosition = position
        }
    }
}

class Swarm {
    var particles: [Particle]
    var globalBest: [Double]?
    var globalBestScore: Double
    var bounds: (Double, Double)?

    init(dimensions: Int, numParticles: Int, bounds: (Double, Double)? = nil) {
        self.particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        self.globalBest = nil
        self.globalBestScore = .infinity
        self.bounds = bounds
    }

    func updateGlobalBest() {
        for particle in particles {
            if particle.bestScore < globalBestScore {
                globalBestScore = particle.bestScore
                globalBest = particle.bestPosition
            }
        }
    }

    func optimize(function: ([Double]) -> Double, iterations: Int) {
        for _ in 0..<iterations {
            updateGlobalBest()
            for particle in particles {
                particle.updateVelocity(globalBest: globalBest ?? [])
                particle.updatePosition(bounds: bounds)
                particle.evaluate(function: function)
            }
        }
    }
}

func objectiveFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + pow($1, 2) }
}

func main() {
    let dimensions = 2
    let numParticles = 30
    let bounds: (Double, Double) = (-10, 10)
    let iterations = 100
    let swarm = Swarm(dimensions: dimensions, numParticles: numParticles, bounds: bounds)
    swarm.optimize(function: objectiveFunction, iterations: iterations)
    print("Global Best Position:", swarm.globalBest ?? [])
    print("Global Best Score:", swarm.globalBestScore)
}

main()