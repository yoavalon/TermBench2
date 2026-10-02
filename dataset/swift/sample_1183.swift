import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var positions: [[Double]]
    var velocities: [[Double]]
    var best_positions: [[Double]]
    var best_scores: [Double]
    var global_best_position: [Double]
    var global_best_score: Double

    init(size: Int, dimensions: Int) {
        self.size = size
        self.dimensions = dimensions
        self.positions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.velocities = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.best_positions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.best_scores = Array(repeating: Double.greatestFiniteMagnitude, count: size)
        self.global_best_position = Array(repeating: 0.0, count: dimensions)
        self.global_best_score = Double.greatestFiniteMagnitude
    }

    func update_global_best() {
        for i in 0..<size {
            let score = evaluate(position: best_positions[i])
            if score < global_best_score {
                global_best_score = score
                global_best_position = best_positions[i]
            }
        }
    }

    func evaluate(position: [Double]) -> Double {
        return position.reduce(0) { $0 + ($1 * $1) }
    }

    func update_particles() {
        for i in 0..<size {
            for j in 0..<dimensions {
                let r1 = 0.5
                let r2 = 0.5
                let c1 = 2.0
                let c2 = 2.0
                velocities[i][j] = 0.7 * velocities[i][j] + c1 * r1 * (best_positions[i][j] - positions[i][j]) + c2 * r2 * (global_best_position[j] - positions[i][j])
                positions[i][j] += velocities[i][j]
            }
            best_scores[i] = evaluate(position: positions[i])
            if best_scores[i] < global_best_score {
                best_positions[i] = positions[i]
            }
        }
    }

    func iterate() {
        update_global_best()
        update_particles()
        iterate()
    }
}

func main() {
    let swarm = Swarm(size: 30, dimensions: 2)
    swarm.iterate()
}

main()