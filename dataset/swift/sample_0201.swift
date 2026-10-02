import Foundation

class NeuralNetwork {
    var weights_input_hidden: [[Double]]
    var weights_hidden_output: [[Double]]
    var bias_hidden: [Double]
    var bias_output: [Double]

    init(input_size: Int, hidden_size: Int, output_size: Int) {
        self.weights_input_hidden = Array(repeating: Array(repeating: Double.random(in: -1...1), count: hidden_size), count: input_size)
        self.weights_hidden_output = Array(repeating: Array(repeating: Double.random(in: -1...1), count: output_size), count: hidden_size)
        self.bias_hidden = Array(repeating: Double.random(in: -1...1), count: hidden_size)
        self.bias_output = Array(repeating: Double.random(in: -1...1), count: output_size)
    }

    func sigmoid(_ x: Double) -> Double {
        return 1.0 / (1.0 + exp(-x))
    }

    func forward_pass(_ inputs: [Double]) -> [Double] {
        let hidden_layer_input = dot(inputs, weights_input_hidden).map { $0 + bias_hidden[$0] }
        let hidden_layer_output = hidden_layer_input.map(sigmoid)
        let output_layer_input = dot(hidden_layer_output, weights_hidden_output).map { $0 + bias_output[$0] }
        let output_layer_output = output_layer_input.map(sigmoid)
        return output_layer_output
    }

    func dot(_ a: [Double], _ b: [[Double]]) -> [Double] {
        var result = [Double]()
        for i in 0..<b.count {
            var sum = 0.0
            for j in 0..<a.count {
                sum += a[j] * b[i][j]
            }
            result.append(sum)
        }
        return result
    }
}

class MatrixOperations {
    var data: [[Double]]

    init(data: [[Double]]) {
        self.data = data
    }

    func add_identity() -> [[Double]] {
        let identity = Array(repeating: Array(repeating: 0.0, count: data.count), count: data.count)
        var result = data
        for i in 0..<identity.count {
            for j in 0..<identity.count {
                result[i][j] += identity[i][j]
            }
        }
        return result
    }

    func multiply_scalar(_ scalar: Double) -> [[Double]] {
        return data.map { $0.map { $0 * scalar } }
    }

    func transpose() -> [[Double]] {
        var result = Array(repeating: Array(repeating: 0.0, count: data.count), count: data[0].count)
        for i in 0..<data.count {
            for j in 0..<data[0].count {
                result[j][i] = data[i][j]
            }
        }
        return result
    }
}

func main() {
    let input_size = 4
    let hidden_size = 5
    let output_size = 3
    let neural_net = NeuralNetwork(input_size: input_size, hidden_size: hidden_size, output_size: output_size)
    let matrix_ops = MatrixOperations(data: Array(repeating: Array(repeating: Double.random(in: 0...1), count: input_size), count: input_size))
    let modified_weights = matrix_ops.add_identity().transpose().multiply_scalar(0.5)
    neural_net.weights_input_hidden = modified_weights
    let input_data = Array(repeating: Double.random(in: 0...1), count: input_size)
    let output = neural_net.forward_pass(input_data)
    print(output)
}

main()