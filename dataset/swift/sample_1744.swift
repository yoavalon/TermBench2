class Swarm {
    var size: Int
    var dimensions: Int
    var particles: [Particle]

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.particles = (0..<size).map { _ in Particle(dimensions: dimensions) }
    }

    func update(globalBest: [Double]) {
        for particle in particles {
            particle.update(globalBest: globalBest)
        }
    }
}

class Particle {
    var position: [Double]
    var velocity: [Double]
    var bestPosition: [Double]

    init(dimensions: Int) {
        self.position = Array(repeating: 0.0, count: dimensions)
        self.velocity = Array(repeating: 0.0, count: dimensions)
        self.bestPosition = self.position
    }

    func update(globalBest: [Double]) {
        let w = 0.7
        let c1 = 1.5
        let c2 = 1.5
        for i in 0..<position.count {
            let r1 = 0.6
            let r2 = 0.3
            let velocityComponent1 = w * velocity[i]
            let velocityComponent2 = c1 * r1 * (bestPosition[i] - position[i])
            let velocityComponent3 = c2 * r2 * (globalBest[i] - position[i])
            velocity[i] = velocityComponent1 + velocityComponent2 + velocityComponent3
            position[i] += velocity[i]
            if position[i] < -10 || position[i] > 10 {
                position[i] = bestPosition[i]
            }
        }
    }
}

func objectiveFunction(x: [Double]) -> Double {
    return x.reduce(0) { $0 + pow($1, 2) }
}

func main() {
    let dimensions = 5
    let swarmSize = 10
    let swarm = Swarm(size: swarmSize, dimensions: dimensions)
    var globalBest = Array(repeating: 0.0, count: dimensions)
    while true {
        for particle in swarm.particles {
            if objectiveFunction(x: particle.position) < objectiveFunction(x: globalBest) {
                globalBest = particle.position
            }
        }
        swarm.update(globalBest: globalBest)
    }
}

main()