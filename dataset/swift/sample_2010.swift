import Foundation

class MatrixOperations {
    var a: [[Float]]
    var b: [[Float]]

    init(a: [[Float]], b: [[Float]]) {
        self.a = a
        self.b = b
    }

    func multiply() -> [[Float]] {
        let rowsA = a.count
        let colsA = a[0].count
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

    func add() -> [[Float]] {
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

    func subtract() -> [[Float]] {
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
    var layers: [MatrixOperations]

    init(layers: [MatrixOperations]) {
        self.layers = layers
    }

    func forwardPass(inputData: [[Float]]) -> [[Float]] {
        var result = inputData
        for layer in layers {
            result = layer.multiply()
        }
        return result
    }
}

func main() {
    let a: [[Float]] = [[1.0, 2.0], [3.0, 4.0]]
    let b: [[Float]] = [[2.0, 0.0], [1.0, 2.0]]
    let c: [[Float]] = [[0.5, 1.5], [2.5, 3.5]]
    let op1 = MatrixOperations(a: a, b: b)
    let op2 = MatrixOperations(a: op1.multiply(), b: c)
    let layers = [op1, op2]
    let nn = NeuralNetwork(layers: layers)
    let inputData: [[Float]] = [[1.0, 1.0], [1.0, 1.0]]
    let output = nn.forwardPass(inputData: inputData)
    print(output)
}

main()