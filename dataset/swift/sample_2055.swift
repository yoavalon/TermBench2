import Foundation

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]
    var bestScore: Double

    init(dimensions: Int) {
        self.position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        self.velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        self.bestPosition = self.position
        self.bestScore = Double.greatestFiniteMagnitude
    }
}

class Swarm {
    var particles: [Particle]
    var globalBestPosition: [Double]
    var globalBestScore: Double

    init(numParticles: Int, dimensions: Int) {
        self.particles = (0..<numParticles).map { _ in Particle(dimensions: dimensions) }
        self.globalBestPosition = (0..<dimensions).map { _ in 0.0 }
        self.globalBestScore = Double.greatestFiniteMagnitude
    }

    func updateGlobalBest() {
        for particle in particles {
            let score = evaluate(position: particle.position)
            if score < globalBestScore {
                globalBestScore = score
                globalBestPosition = particle.position
            }
        }
    }

    func evaluate(position: [Double]) -> Double {
        return position.map { $0 * $0 }.reduce(0, +)
    }

    func updateParticles(w: Double, c1: Double, c2: Double) {
        for particle in particles {
            for i in 0..<particle.position.count {
                let r1 = Double.random(in: 0...1)
                let r2 = Double.random(in: 0...1)
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.bestPosition[i] - particle.position[i]) + c2 * r2 * (globalBestPosition[i] - particle.position[i])
                particle.position[i] += particle.velocity[i]
                let newScore = evaluate(position: particle.position)
                if newScore < particle.bestScore {
                    particle.bestScore = newScore
                    particle.bestPosition = particle.position
                }
            }
        }
    }
}

func main() {
    let dimensions = 30
    let numParticles = 30
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let iterations = 100
    let swarm = Swarm(numParticles: numParticles, dimensions: dimensions)
    for _ in 0..<iterations {
        swarm.updateGlobalBest()
        swarm.updateParticles(w: w, c1: c1, c2: c2)
    }
    print("Best score: \(swarm.globalBestScore)")
}

main()