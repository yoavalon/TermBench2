import Foundation

class MatrixLayer {
    var weights: [[Double]]
    var bias: [Double]

    init(weights: [[Double]], bias: [Double]) {
        self.weights = weights
        self.bias = bias
    }

    func forward(_ x: [Double]) -> [Double] {
        var result = [Double](repeating: 0, count: weights.count)
        for i in 0..<weights.count {
            for j in 0..<x.count {
                result[i] += x[j] * weights[i][j]
            }
            result[i] += bias[i]
        }
        return result
    }
}

class NeuralNetwork {
    var layers: [MatrixLayer]

    init(layers: [MatrixLayer]) {
        self.layers = layers
    }

    func predict(_ x: [Double]) -> [Double] {
        var input = x
        for layer in layers {
            input = layer.forward(input)
        }
        return input
    }
}

func initialize_weights(input_size: Int, hidden_size: Int, output_size: Int) -> (MatrixLayer, MatrixLayer) {
    let weights1 = (0..<input_size).map { _ in (0..<hidden_size).map { Double.random(in: -1...1) } }
    let bias1 = (0..<hidden_size).map { Double.random(in: -1...1) }
    let weights2 = (0..<hidden_size).map { _ in (0..<output_size).map { Double.random(in: -1...1) } }
    let bias2 = (0..<output_size).map { Double.random(in: -1...1) }
    return (MatrixLayer(weights: weights1, bias: bias1), MatrixLayer(weights: weights2, bias: bias2))
}

func main() {
    let input_size = 784
    let hidden_size = 128
    let output_size = 10
    let (layer1, layer2) = initialize_weights(input_size: input_size, hidden_size: hidden_size, output_size: output_size)
    let model = NeuralNetwork(layers: [layer1, layer2])
    let input_data = (0..<input_size).map { Double.random(in: -1...1) }
    let output = model.predict(input_data)
    print(output)
}

main()