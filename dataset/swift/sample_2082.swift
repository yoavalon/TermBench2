import Foundation
import Accelerate

class Layer {
    var weights: [[Double]]
    var bias: [Double]

    init(inputSize: Int, outputSize: Int) {
        self.weights = Array(repeating: Array(repeating: 0.0, count: outputSize), count: inputSize)
        self.bias = Array(repeating: 0.0, count: outputSize)
        for i in 0..<inputSize {
            for j in 0..<outputSize {
                self.weights[i][j] = Double.random(in: -1.0...1.0)
            }
        }
        for j in 0..<outputSize {
            self.bias[j] = Double.random(in: -1.0...1.0)
        }
    }

    func forward(_ x: [[Double]]) -> [[Double]] {
        let (rows, cols) = (x.count, x[0].count)
        let (wRows, wCols) = (weights.count, weights[0].count)
        var result = Array(repeating: Array(repeating: 0.0, count: wCols), count: rows)
        vvdot(&result, x, weights, [cols, wCols, rows], [cols, wCols])
        for i in 0..<rows {
            for j in 0..<wCols {
                result[i][j] += bias[j]
            }
        }
        return result
    }
}

func relu(_ x: [[Double]]) -> [[Double]] {
    let (rows, cols) = (x.count, x[0].count)
    var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            result[i][j] = max(0, x[i][j])
        }
    }
    return result
}

func softmax(_ x: [[Double]]) -> [[Double]] {
    let (rows, cols) = (x.count, x[0].count)
    var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        let maxVal = x[i].max()!
        var sum = 0.0
        for j in 0..<cols {
            result[i][j] = exp(x[i][j] - maxVal)
            sum += result[i][j]
        }
        for j in 0..<cols {
            result[i][j] /= sum
        }
    }
    return result
}

func neuralNetworkForwardPass(_ inputData: [[Double]], _ layers: [Layer]) -> [[Double]] {
    var a = inputData
    for layer in layers {
        a = relu(layer.forward(a))
    }
    return softmax(a)
}

func generateData(batchSize: Int, inputSize: Int) -> [[Double]] {
    var data = Array(repeating: Array(repeating: 0.0, count: inputSize), count: batchSize)
    for i in 0..<batchSize {
        for j in 0..<inputSize {
            data[i][j] = Double.random(in: -1.0...1.0)
        }
    }
    return data
}

func main() {
    let inputSize = 784
    let hiddenSize = 256
    let outputSize = 10
    let batchSize = 64
    let layers = [Layer(inputSize: inputSize, outputSize: hiddenSize), Layer(inputSize: hiddenSize, outputSize: outputSize)]
    let inputData = generateData(batchSize: batchSize, inputSize: inputSize)
    let output = neuralNetworkForwardPass(inputData, layers)
    print(output)
}

main()