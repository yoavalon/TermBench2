import Foundation

class Activation {
    
    func sigmoid(_ x: Double) -> Double {
        return 1.0 / (1.0 + exp(-x))
    }
    
    func relu(_ x: Double) -> Double {
        return max(0.0, x)
    }
}

class Layer {
    
    var weights: [[Double]]
    var bias: [Double]
    var activation: (Double) -> Double
    
    init(weights: [[Double]], bias: [Double], activation: @escaping (Double) -> Double) {
        self.weights = weights
        self.bias = bias
        self.activation = activation
    }
    
    func forward(_ input_data: [Double]) -> [Double] {
        var z = [Double]()
        for i in 0..<bias.count {
            var sum = bias[i]
            for j in 0..<input_data.count {
                sum += input_data[j] * weights[j][i]
            }
            z.append(sum)
        }
        return z.map(activation)
    }
}

class NeuralNetwork {
    
    var layers: [Layer]
    
    init(layers: [Layer]) {
        self.layers = layers
    }
    
    func predict(_ input_data: [[Double]]) -> [[Double]] {
        var output = input_data
        for layer in layers {
            output = output.map { layer.forward($0) }
        }
        return output
    }
}

func initialize_network(layer_sizes: [Int], activation_type: String) -> NeuralNetwork {
    let activation = Activation()
    var layers: [Layer] = []
    for i in 0..<(layer_sizes.count - 1) {
        let weights = (0..<layer_sizes[i]).map { _ in
            (0..<layer_sizes[i + 1]).map { _ in Double.random(in: -1...1) }
        }
        let bias = (0..<layer_sizes[i + 1]).map { _ in Double.random(in: -1...1) }
        if activation_type == "sigmoid" {
            layers.append(Layer(weights: weights, bias: bias, activation: activation.sigmoid))
        } else if activation_type == "relu" {
            layers.append(Layer(weights: weights, bias: bias, activation: activation.relu))
        }
    }
    return NeuralNetwork(layers: layers)
}

func main() {
    let input_data: [[Double]] = [[0, 0], [0, 1], [1, 0], [1, 1]]
    let expected_output: [[Double]] = [[0], [1], [1], [0]]
    let network = initialize_network(layer_sizes: [2, 4, 1], activation_type: "sigmoid")
    let output = network.predict(input_data)
    print(output)
}

main()