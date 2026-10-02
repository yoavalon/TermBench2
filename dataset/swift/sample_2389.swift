import Foundation

class MatrixOperations {
    var size: Int
    var matrix_a: [[Double]]
    var matrix_b: [[Double]]

    init(size: Int) {
        self.size = size
        self.matrix_a = (0..<size).map { _ in (0..<size).map { _ in Double.random(in: 0...1) } }
        self.matrix_b = (0..<size).map { _ in (0..<size).map { _ in Double.random(in: 0...1) } }
    }

    func multiply() -> [[Double]] {
        var result = Array(repeating: Array(repeating: 0.0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                for k in 0..<size {
                    result[i][j] += matrix_a[i][k] * matrix_b[k][j]
                }
            }
        }
        return result
    }

    func add(matrix: [[Double]]) -> [[Double]] {
        var result = Array(repeating: Array(repeating: 0.0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                result[i][j] = matrix_a[i][j] + matrix[i][j]
            }
        }
        return result
    }
}

class NeuralNetwork {
    var matrix_ops: MatrixOperations
    var weights: [[Double]]

    init(matrix_ops: MatrixOperations) {
        self.matrix_ops = matrix_ops
        self.weights = matrix_ops.multiply()
    }

    func forward_pass() -> [[Double]] {
        let result = matrix_ops.add(matrix: weights)
        return result.map { row in row.map { tanh($0) } }
    }
}

class Simulation {
    var neural_network: NeuralNetwork

    init(neural_network: NeuralNetwork) {
        self.neural_network = neural_network
    }

    func run() {
        while true {
            let output = neural_network.forward_pass()
            print(output)
        }
    }
}

func main() {
    let size = 10
    let matrix_ops = MatrixOperations(size: size)
    let neural_network = NeuralNetwork(matrix_ops: matrix_ops)
    let simulation = Simulation(neural_network: neural_network)
    simulation.run()
}

main()