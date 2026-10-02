import Foundation

class MatrixOperations {
    var a: [[Double]]
    var b: [[Double]]

    init(a: [[Double]], b: [[Double]]) {
        self.a = a
        self.b = b
    }

    func multiply() -> [[Double]] {
        let rowsA = a.count
        let colsA = a[0].count
        let rowsB = b.count
        let colsB = b[0].count
        var result = Array(repeating: Array(repeating: 0.0, count: colsB), count: rowsA)

        for i in 0..<rowsA {
            for j in 0..<colsB {
                for k in 0..<colsA {
                    result[i][j] += a[i][k] * b[k][j]
                }
            }
        }
        return result
    }

    func add() -> [[Double]] {
        let rows = a.count
        let cols = a[0].count
        var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)

        for i in 0..<rows {
            for j in 0..<cols {
                result[i][j] = a[i][j] + b[i][j]
            }
        }
        return result
    }

    func subtract() -> [[Double]] {
        let rows = a.count
        let cols = a[0].count
        var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)

        for i in 0..<rows {
            for j in 0..<cols {
                result[i][j] = a[i][j] - b[i][j]
            }
        }
        return result
    }
}

class NeuralNetwork {
    var weights: [[Double]]
    var biases: [Double]

    init(weights: [[Double]], biases: [Double]) {
        self.weights = weights
        self.biases = biases
    }

    func forward_pass(input_data: [[Double]]) -> [Double] {
        let operations = MatrixOperations(a: input_data, b: weights)
        let weighted_sum = operations.multiply()
        let biased_sum = operations.add(biases.map { [$0] })
        return activation_function(biased_sum)
    }

    func activation_function(_ x: [[Double]]) -> [Double] {
        return x.map { $0.map { max(0, $0) } }.flatMap { $0 }
    }
}

func main() {
    let input_data = [[1.0, 2.0], [3.0, 4.0]]
    let weights = [[0.1, 0.2], [0.3, 0.4]]
    let biases = [0.5, 0.6]
    let nn = NeuralNetwork(weights: weights, biases: biases)
    let output = nn.forward_pass(input_data: input_data)
    print(output)
}

main()