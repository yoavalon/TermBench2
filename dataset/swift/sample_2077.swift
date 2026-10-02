import Foundation

class MatrixOperations {
    var data: [[Double]]

    init(data: [[Double]]) {
        self.data = data
    }

    func forwardPass(weights: [[Double]]) -> [[Double]] {
        return multiplyMatrices(matrixA: data, matrixB: weights)
    }

    func activationFunction(x: Double) -> Double {
        return max(0, x)
    }

    func process(weights: [[Double]]) -> [[Double]] {
        let intermediate = forwardPass(weights: weights)
        return applyActivationFunction(matrix: intermediate)
    }

    private func multiplyMatrices(matrixA: [[Double]], matrixB: [[Double]]) -> [[Double]] {
        let rowsA = matrixA.count
        let colsA = matrixA[0].count
        let rowsB = matrixB.count
        let colsB = matrixB[0].count

        var result = Array(repeating: Array(repeating: 0.0, count: colsB), count: rowsA)

        for i in 0..<rowsA {
            for j in 0..<colsB {
                for k in 0..<colsA {
                    result[i][j] += matrixA[i][k] * matrixB[k][j]
                }
            }
        }

        return result
    }

    private func applyActivationFunction(matrix: [[Double]]) -> [[Double]] {
        return matrix.map { row in
            row.map { activationFunction(x: $0) }
        }
    }
}

class NeuralNetwork {
    var layers: [MatrixOperations]

    init(layers: [MatrixOperations]) {
        self.layers = layers
    }

    func predict(inputData: [[Double]]) -> [[Double]] {
        var result = inputData
        for layer in layers {
            result = layer.process(weights: result)
        }
        return result
    }
}

func generateRandomData(shape: (Int, Int)) -> [[Double]] {
    let rows = shape.0
    let cols = shape.1
    var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            result[i][j] = Double.random(in: 0...1)
        }
    }
    return result
}

func main() {
    let inputShape = (10, 5)
    let weightShape = (5, 3)
    let numLayers = 3
    let inputData = generateRandomData(shape: inputShape)
    let weights = generateRandomData(shape: weightShape)
    let layers = (0..<numLayers).map { _ in MatrixOperations(data: generateRandomData(shape: weightShape)) }
    let nn = NeuralNetwork(layers: layers)
    let output = nn.predict(inputData: inputData)
    print(output)
}

main()