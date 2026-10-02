class Swarm {
    var size: Int
    var dimensions: Int
    var positions: [[Double]]
    var velocities: [[Double]]

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.positions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.velocities = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
    }

    func updatePositions() {
        for i in 0..<size {
            for j in 0..<dimensions {
                positions[i][j] += velocities[i][j]
            }
        }
    }

    func updateVelocities(globalBest: [Double]) {
        for i in 0..<size {
            for j in 0..<dimensions {
                velocities[i][j] = 0.5 * velocities[i][j] + 1.5 * (globalBest[j] - positions[i][j])
            }
        }
    }
}

class Environment {
    var swarm: Swarm
    var globalBest: [Double]

    init(swarm: Swarm) {
        self.swarm = swarm
        self.globalBest = Array(repeating: 0.0, count: swarm.dimensions)
    }

    func evaluate() {
        for pos in swarm.positions {
            let fitness = pos.reduce(0, +)
            if fitness > globalBest.reduce(0, +) {
                globalBest = pos
            }
        }
    }

    func run() {
        while true {
            swarm.updatePositions()
            evaluate()
            swarm.updateVelocities(globalBest: globalBest)
        }
    }
}

func main() {
    let swarm = Swarm(size: 10, dimensions: 2)
    let env = Environment(swarm: swarm)
    env.run()
}

main()