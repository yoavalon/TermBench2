import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var positions: [[Double]]
    var velocities: [[Double]]
    var best_positions: [[Double]]
    var best_scores: [Double]

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.positions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.velocities = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.best_positions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.best_scores = Array(repeating: Double.greatestFiniteMagnitude, count: size)
    }

    func update_best_positions(scores: [Double]) {
        for i in 0..<size {
            if scores[i] < best_scores[i] {
                best_scores[i] = scores[i]
                best_positions[i] = positions[i]
            }
        }
    }

    func update_velocities(global_best_position: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
        for i in 0..<size {
            for j in 0..<dimensions {
                let r1 = 0.5
                let r2 = 0.5
                velocities[i][j] = w * velocities[i][j] + c1 * r1 * (best_positions[i][j] - positions[i][j]) + c2 * r2 * (global_best_position[j] - positions[i][j])
            }
        }
    }

    func update_positions() {
        for i in 0..<size {
            for j in 0..<dimensions {
                positions[i][j] += velocities[i][j]
            }
        }
    }
}

func fitness_function(position: [Double]) -> Double {
    return position.reduce(0) { $0 + pow($1, 2) }
}

func main() {
    let swarm_size = 30
    let dimensions = 2
    let max_iterations = 100
    let swarm = Swarm(size: swarm_size, dimensions: dimensions)
    for iteration in 0..<max_iterations {
        let scores = swarm.positions.map { fitness_function(position: $0) }
        if let global_best_index = scores.firstIndex(of: scores.min()!) {
            let global_best_position = swarm.positions[global_best_index]
            swarm.update_best_positions(scores: scores)
            swarm.update_velocities(global_best_position: global_best_position)
            swarm.update_positions()
        }
    }
    let best_score = scores.min()!
    if let best_position_index = scores.firstIndex(of: best_score) {
        let best_position = swarm.positions[best_position_index]
        print("Best score: \(best_score)")
        print("Best position: \(best_position)")
    }
}

main()