import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var particles: [[Double]]
    var velocities: [[Double]]
    var bestPositions: [[Double]]
    var bestScores: [Double]
    var globalBest: [Double]
    var globalBestScore: Double

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.particles = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.velocities = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.bestPositions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.bestScores = Array(repeating: Double.greatestFiniteMagnitude, count: size)
        self.globalBest = Array(repeating: 0.0, count: dimensions)
        self.globalBestScore = Double.greatestFiniteMagnitude
    }

    func updateGlobalBest() {
        for i in 0..<size {
            if bestScores[i] < globalBestScore {
                globalBestScore = bestScores[i]
                globalBest = bestPositions[i]
            }
        }
    }

    func updateParticles() {
        for i in 0..<size {
            for j in 0..<dimensions {
                let r1 = 0.5
                let r2 = 0.5
                let cognitive = r1 * (bestPositions[i][j] - particles[i][j])
                let social = r2 * (globalBest[j] - particles[i][j])
                velocities[i][j] += cognitive + social
                particles[i][j] += velocities[i][j]
            }
        }
    }

    func evaluate(objectiveFunction: (Double) -> Double) {
        for i in 0..<size {
            let score = particles[i].reduce(0) { $0 + $1 * $1 }
            if score < bestScores[i] {
                bestScores[i] = score
                bestPositions[i] = particles[i]
            }
        }
        updateGlobalBest()
    }
}

class Optimization {
    var swarm: Swarm
    var objectiveFunction: (Double) -> Double

    init(swarm: Swarm, objectiveFunction: @escaping (Double) -> Double) {
        self.swarm = swarm
        self.objectiveFunction = objectiveFunction
    }

    func run() {
        while true {
            swarm.updateParticles()
            swarm.evaluate(objectiveFunction: objectiveFunction)
        }
    }
}

func objectiveFunction(position: [Double]) -> Double {
    return position.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let size = 30
    let dimensions = 2
    let swarm = Swarm(size: size, dimensions: dimensions)
    let optimization = Optimization(swarm: swarm, objectiveFunction: objectiveFunction)
    optimization.run()
}

main()