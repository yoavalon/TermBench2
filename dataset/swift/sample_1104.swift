import Foundation

class MatrixOperations {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func multiply(otherMatrix: [[Double]]) -> [[Double]] {
        let rowsA = matrix.count
        let colsA = matrix[0].count
        let colsB = otherMatrix[0].count
        var result = Array(repeating: Array(repeating: 0.0, count: colsB), count: rowsA)

        for i in 0..<rowsA {
            for j in 0..<colsB {
                for k in 0..<colsA {
                    result[i][j] += matrix[i][k] * otherMatrix[k][j]
                }
            }
        }
        return result
    }

    func add(otherMatrix: [[Double]]) -> [[Double]] {
        let rows = matrix.count
        let cols = matrix[0].count
        var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)

        for i in 0..<rows {
            for j in 0..<cols {
                result[i][j] = matrix[i][j] + otherMatrix[i][j]
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

    func forwardPass(inputData: [[Double]]) -> [[Double]] {
        var currentData = inputData
        for layer in layers {
            currentData = layer.multiply(otherMatrix: currentData)
        }
        return currentData
    }
}

class RecursiveProcess {
    var neuralNetwork: NeuralNetwork
    var inputData: [[Double]]

    init(neuralNetwork: NeuralNetwork, inputData: [[Double]]) {
        self.neuralNetwork = neuralNetwork
        self.inputData = inputData
    }

    func process(currentData: [[Double]]) {
        let outputData = neuralNetwork.forwardPass(inputData: currentData)
        process(currentData: outputData)
    }
}

func main() {
    let matrix1 = [[0.5, 0.2], [0.3, 0.7]]
    let matrix2 = [[0.1, 0.4], [0.9, 0.5]]
    let layers = [MatrixOperations(matrix: matrix1), MatrixOperations(matrix: matrix2)]
    let neuralNetwork = NeuralNetwork(layers: layers)
    let inputData = [[1.0], [1.0]]
    let recursiveProcess = RecursiveProcess(neuralNetwork: neuralNetwork, inputData: inputData)
    recursiveProcess.process(currentData: inputData)
}

main()