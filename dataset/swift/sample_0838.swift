import Foundation

class Swarm {
    var size: Int
    var dimensions: Int
    var bounds: [[Double]]
    var positions: [[Double]]
    var velocities: [[Double]]
    var pbest_positions: [[Double]]
    var pbest_scores: [Double]
    var gbest_position: [Double]
    var gbest_score: Double

    init(size: Int, dimensions: Int, bounds: [[Double]]) {
        self.size = size
        self.dimensions = dimensions
        self.bounds = bounds
        self.positions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.velocities = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.pbest_positions = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
        self.pbest_scores = Array(repeating: .greatestFiniteMagnitude, count: size)
        self.gbest_position = Array(repeating: 0.0, count: dimensions)
        self.gbest_score = .greatestFiniteMagnitude
    }

    func initialize() {
        for i in 0..<size {
            for j in 0..<dimensions {
                positions[i][j] = (bounds[j][1] - bounds[j][0]) * Double.random(in: 0...1) + bounds[j][0]
                velocities[i][j] = (bounds[j][1] - bounds[j][0]) * Double.random(in: 0...1) - (bounds[j][1] - bounds[j][0]) / 2
            }
        }
    }

    func evaluate(function: ( [Double]) -> Double) {
        for i in 0..<size {
            let score = function(positions[i])
            if score < pbest_scores[i] {
                pbest_scores[i] = score
                pbest_positions[i] = positions[i]
            }
            if score < gbest_score {
                gbest_score = score
                gbest_position = positions[i]
            }
        }
    }

    func update_velocities(w: Double, c1: Double, c2: Double) {
        for i in 0..<size {
            for j in 0..<dimensions {
                velocities[i][j] = w * velocities[i][j] + c1 * Double.random(in: 0...1) * (pbest_positions[i][j] - positions[i][j]) + c2 * Double.random(in: 0...1) * (gbest_position[j] - positions[i][j])
            }
        }
    }

    func update_positions() {
        for i in 0..<size {
            for j in 0..<dimensions {
                positions[i][j] += velocities[i][j]
                positions[i][j] = max(bounds[j][0], min(bounds[j][1], positions[i][j]))
            }
        }
    }

    func optimize(function: ( [Double]) -> Double, iterations: Int) -> Double {
        initialize()
        for _ in 0..<iterations {
            evaluate(function: function)
            update_velocities(w: 0.7, c1: 1.5, c2: 1.5)
            update_positions()
        }
        return gbest_score
    }
}

func objective(x: [Double]) -> Double {
    return x.map { ($0 - 0.5) ** 2 }.reduce(0, +)
}

func main() {
    let dimensions = 3
    let bounds = Array(repeating: [-10, 10], count: dimensions)
    let swarm_size = 30
    let iterations = 100
    let swarm = Swarm(size: swarm_size, dimensions: dimensions, bounds: bounds)
    let best_score = swarm.optimize(function: objective, iterations: iterations)
    print(best_score)
}

main()