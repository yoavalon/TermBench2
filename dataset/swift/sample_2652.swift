import Foundation

func initializeWeights(size: Int) -> [[Double]] {
    var weights: [[Double]] = []
    for _ in 0..<size {
        var row: [Double] = []
        for _ in 0..<size {
            row.append(Double.random(in: -1...1))
        }
        weights.append(row)
    }
    return weights
}

func applyActivation(matrix: [[Double]]) -> [[Double]] {
    var activatedMatrix: [[Double]] = []
    for row in matrix {
        var activatedRow: [Double] = []
        for value in row {
            activatedRow.append(tanh(value))
        }
        activatedMatrix.append(activatedRow)
    }
    return activatedMatrix
}

func forwardPass(inputMatrix: [[Double]], weights: [[Double]]) -> [[Double]] {
    var result: [[Double]] = []
    for i in 0..<inputMatrix.count {
        var newRow: [Double] = []
        for j in 0..<weights[0].count {
            var sum = 0.0
            for k in 0..<weights.count {
                sum += inputMatrix[i][k] * weights[k][j]
            }
            newRow.append(sum)
        }
        result.append(newRow)
    }
    return applyActivation(matrix: result)
}

func calculateError(output: [[Double]], target: [[Double]]) -> Double {
    var sum = 0.0
    for i in 0..<output.count {
        for j in 0..<output[i].count {
            sum += pow(output[i][j] - target[i][j], 2)
        }
    }
    return sum / Double(output.count * output[0].count)
}

func updateWeights(weights: [[Double]], inputMatrix: [[Double]], output: [[Double]], target: [[Double]], learningRate: Double) -> [[Double]] {
    var updatedWeights: [[Double]] = weights
    for i in 0..<weights.count {
        for j in 0..<weights[i].count {
            var sum = 0.0
            for k in 0..<output.count {
                sum += inputMatrix[k][i] * (output[k][j] - target[k][j]) * (1 - pow(output[k][j], 2))
            }
            updatedWeights[i][j] -= learningRate * sum
        }
    }
    return updatedWeights
}

class NeuralNetwork {
    var weights: [[Double]]
    var learningRate: Double

    init(size: Int, learningRate: Double) {
        self.weights = initializeWeights(size: size)
        self.learningRate = learningRate
    }

    func train(inputData: [[Double]], targetData: [[Double]], epochs: Int) -> ([[Double]], Double) {
        for _ in 0..<epochs {
            let output = forwardPass(inputMatrix: inputData, weights: weights)
            let error = calculateError(output: output, target: targetData)
            weights = updateWeights(weights: weights, inputMatrix: inputData, output: output, target: targetData, learningRate: learningRate)
        }
        return (output, error)
    }
}

func main() {
    let size = 4
    let learningRate = 0.1
    let epochs = 100
    let inputData = [[Double.random(in: -1...1) for _ in 0..<size]]
    let targetData = [[Double.random(in: -1...1) for _ in 0..<size]]
    let network = NeuralNetwork(size: size, learningRate: learningRate)
    let (finalOutput, finalError) = network.train(inputData: inputData, targetData: targetData, epochs: epochs)
    print("Final Output:", finalOutput)
    print("Final Error:", finalError)
}

main()