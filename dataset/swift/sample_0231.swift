import Foundation

class MatrixOperations {
    var matrix_a: [[Double]]
    var matrix_b: [[Double]]

    init(matrix_a: [[Double]], matrix_b: [[Double]]) {
        self.matrix_a = matrix_a
        self.matrix_b = matrix_b
    }

    func multiply() -> [[Double]] {
        let rows = matrix_a.count
        let cols = matrix_b[0].count
        let inner = matrix_b.count

        var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)

        for i in 0..<rows {
            for j in 0..<cols {
                for k in 0..<inner {
                    result[i][j] += matrix_a[i][k] * matrix_b[k][j]
                }
            }
        }

        return result
    }

    func transpose() -> [[Double]] {
        let rows = matrix_a.count
        let cols = matrix_a[0].count

        var result = Array(repeating: Array(repeating: 0.0, count: rows), count: cols)

        for i in 0..<rows {
            for j in 0..<cols {
                result[j][i] = matrix_a[i][j]
            }
        }

        return result
    }
}

class NeuralNetwork {
    var weights: [[Double]]
    var input_data: [Double]

    init(weights: [[Double]], input_data: [Double]) {
        self.weights = weights
        self.input_data = input_data
    }

    func forward_pass() -> [Double] {
        let rows = weights.count
        let cols = input_data.count

        var result = Array(repeating: 0.0, count: rows)

        for i in 0..<rows {
            for j in 0..<cols {
                result[i] += weights[i][j] * input_data[j]
            }
        }

        return result
    }

    func activate(_ data: [Double]) -> [Double] {
        return data.map { max($0, 0.0) }
    }
}

func main() {
    let matrix_a = [[1.0, 2.0], [3.0, 4.0]]
    let matrix_b = [[2.0, 0.0], [1.0, 2.0]]
    let matrix_ops = MatrixOperations(matrix_a: matrix_a, matrix_b: matrix_b)
    let product = matrix_ops.multiply()
    let transposed_a = matrix_ops.transpose()
    let weights = [[0.5, 0.2], [0.3, 0.4]]
    let input_data = [1.0, 0.5]
    let nn = NeuralNetwork(weights: weights, input_data: input_data)
    let forward_output = nn.forward_pass()
    let activated_output = nn.activate(forward_output)

    print("Matrix Product:\n\(product.map { $0.map { String($0) }.joined(separator: " ") }.joined(separator: "\n"))")
    print("Transposed A:\n\(transposed_a.map { $0.map { String($0) }.joined(separator: " ") }.joined(separator: "\n"))")
    print("Neural Network Forward Pass Output:\n\(forward_output.map { String($0) }.joined(separator: " "))")
    print("Activated Output:\n\(activated_output.map { String($0) }.joined(separator: " "))")
}

main()