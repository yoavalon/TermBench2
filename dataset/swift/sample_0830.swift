import Foundation

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let result = Array(repeating: Array(repeating: 0.0, count: b[0].count), count: a.count)
    for i in 0..<a.count {
        for j in 0..<b[0].count {
            for k in 0..<a[0].count {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    return result
}

func activate(_ x: Double) -> Double {
    return max(0, x)
}

func forwardPass(_ weights: [[Double]], _ biases: [[Double]], _ input_data: [[Double]], _ depth: Int) -> [[Double]] {
    if depth == 0 {
        return input_data
    }
    var layer_output = matrixMultiply(input_data, weights)
    for i in 0..<layer_output.count {
        for j in 0..<layer_output[i].count {
            layer_output[i][j] = activate(layer_output[i][j] + biases[0][j])
        }
    }
    return forwardPass(weights, biases, layer_output, depth - 1)
}

class NeuralNetwork {
    var weights: [[Double]]
    var biases: [[Double]]

    init(layers: [Int], input_size: Int) {
        weights = [Array(repeating: 0.0, count: layers[0])]
        biases = [Array(repeating: 0.0, count: layers[0])]
        for i in 0..<layers.count {
            weights.append(Array(repeating: 0.0, count: layers[i]))
            biases.append(Array(repeating: 0.0, count: layers[i]))
        }
        for i in 0..<weights.count {
            for j in 0..<weights[i].count {
                weights[i][j] = Double.random(in: -1...1)
                biases[i][j] = Double.random(in: -1...1)
            }
        }
    }

    func predict(_ input_data: [[Double]], _ depth: Int) -> [[Double]] {
        return forwardPass(weights, biases, input_data, depth)
    }
}

func main() {
    let input_data = Array(repeating: Double.random(in: -1...1), count: 10)
    let network = NeuralNetwork(layers: [20, 15, 5], input_size: 10)
    let output = network.predict([input_data], 3)
    print(output)
}

main()