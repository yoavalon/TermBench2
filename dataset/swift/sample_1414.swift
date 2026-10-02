import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var positions: [[Double]]
    var velocities: [[Double]]
    var bestPositions: [[Double]]
    var bestScore: Double

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.positions = (0..<size).map { _ in (0..<dimensions).map { _ in Double.random(in: 0...1) } }
        self.velocities = (0..<size).map { _ in (0..<dimensions).map { _ in Double.random(in: 0...1) } }
        self.bestPositions = positions.map { Array($0) }
        self.bestScore = .infinity
    }

    func updatePersonalBest(score: Double) {
        if score < bestScore {
            bestScore = score
            bestPositions = positions.map { Array($0) }
        }
    }

    func updateVelocity(globalBest: [Double]) {
        let inertia = 0.5
        let cognitive = 1.5
        let social = 1.5
        for i in 0..<size {
            for j in 0..<dimensions {
                let r1 = Double.random(in: 0...1)
                let r2 = Double.random(in: 0...1)
                velocities[i][j] = inertia * velocities[i][j] + cognitive * r1 * (bestPositions[i][j] - positions[i][j]) + social * r2 * (globalBest[j] - positions[i][j])
            }
        }
    }

    func updatePosition() {
        for i in 0..<size {
            for j in 0..<dimensions {
                positions[i][j] += velocities[i][j]
            }
        }
    }
}

class Environment {
    var swarm: Swarm

    init(swarm: Swarm) {
        self.swarm = swarm
    }

    func evaluate() -> [Double] {
        var scores = [Double]()
        for position in swarm.positions {
            let score = position.map { $0 * $0 }.reduce(0, +)
            scores.append(score)
        }
        return scores
    }

    func findGlobalBest(scores: [Double]) -> [Double] {
        let globalBestIndex = scores.firstIndex(of: scores.min()!)!
        return swarm.positions[globalBestIndex]
    }
}

func main() {
    let swarm = Swarm(size: 10, dimensions: 3)
    let environment = Environment(swarm: swarm)
    let iterations = 50
    for _ in 0..<iterations {
        let scores = environment.evaluate()
        let globalBest = environment.findGlobalBest(scores: scores)
        swarm.updatePersonalBest(score: scores.min()!)
        swarm.updateVelocity(globalBest: globalBest)
        swarm.updatePosition()
    }
    print("Best score: \(swarm.bestScore)")
}

main()