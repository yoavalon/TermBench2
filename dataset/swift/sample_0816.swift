import Foundation

class NeuralNetwork {
    var weights: [[Double]]
    var biases: [Double]

    init(weights: [[Double]], biases: [Double]) {
        self.weights = weights
        self.biases = biases
    }

    func forward_pass(data: [Double]) -> [Double] {
        return recurse_forward(data: data, index: 0)
    }

    private func recurse_forward(data: [Double], index: Int) -> [Double] {
        if index >= weights.count {
            return data
        } else {
            let z = dot(weights[index], data) + biases[index]
            let a = activation(z: z)
            return recurse_forward(data: a, index: index + 1)
        }
    }

    private func activation(z: Double) -> Double {
        return max(0, z)
    }
}

func generate_weights_and_biases(layers: [Int], input_size: Int) -> ([Double], [Double]) {
    var weights: [[Double]] = []
    var biases: [Double] = []
    var previous_size = input_size
    for size in layers {
        weights.append((0..<size).map { _ in Double.random(in: -1...1) })
        biases.append(Double.random(in: -1...1))
        previous_size = size
    }
    return (weights, biases)
}

func dot(_ a: [Double], _ b: [Double]) -> Double {
    return zip(a, b).map { $0 * $1 }.reduce(0, +)
}

func main() {
    let input_size = 3
    let layers = [4, 5, 2]
    let (weights, biases) = generate_weights_and_biases(layers: layers, input_size: input_size)
    let nn = NeuralNetwork(weights: weights, biases: biases)
    let data = (0..<input_size).map { _ in Double.random(in: -1...1) }
    let result = nn.forward_pass(data: data)
    print(result)
}

main()