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

    func updateVelocity(globalBest: Particle) {
        let w = 0.729
        let c1 = 1.494
        let c2 = 1.494
        for i in 0..<self.velocity.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (self.bestPosition[i] - self.position[i])
            let social = c2 * r2 * (globalBest.bestPosition[i] - self.position[i])
            self.velocity[i] = w * self.velocity[i] + cognitive + social
        }
    }

    func updatePosition() {
        for i in 0..<self.position.count {
            self.position[i] += self.velocity[i]
            self.position[i] = max(-10, min(10, self.position[i]))
        }
    }

    func evaluate(objectiveFunction: (Particle) -> Double) {
        self.bestScore = objectiveFunction(self)
        if self.bestScore < self.bestScore {
            self.bestPosition = self.position
        }
    }
}

class Swarm {
    var size: Int
    var dimensions: Int
    var particles: [Particle]
    var globalBest: Particle?

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
        self.globalBest = nil
    }

    func updateGlobalBest() {
        for particle in self.particles {
            if self.globalBest == nil || particle.bestScore < self.globalBest!.bestScore {
                self.globalBest = particle
            }
        }
    }

    func updateParticles() {
        for particle in self.particles {
            particle.updateVelocity(globalBest: self.globalBest!)
            particle.updatePosition()
        }
    }
}

func objectiveFunction(particle: Particle) -> Double {
    return particle.position.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let swarmSize = 30
    let dimensions = 2
    let swarm = Swarm(size: swarmSize, dimensions: dimensions)
    for _ in 0..<100 {
        swarm.updateGlobalBest()
        for particle in swarm.particles {
            particle.evaluate(objectiveFunction: objectiveFunction)
        }
        swarm.updateParticles()
    }
    if let globalBest = swarm.globalBest {
        print(globalBest.bestScore, globalBest.bestPosition)
    }
}

main()