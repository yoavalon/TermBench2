import Foundation

class Network {
    var layers: [Int]
    var weights: [[Double]]
    var biases: [[Double]]

    init(layers: [Int]) {
        self.layers = layers
        self.weights = (0..<(layers.count - 1)).map { _ in
            Array(repeating: Double.random(in: -1...1), count: layers[$0] * layers[$0 + 1])
        }
        self.biases = (0..<(layers.count - 1)).map { _ in
            Array(repeating: Double.random(in: -1...1), count: layers[$0 + 1])
        }
    }

    func forward(inputData: [Double]) -> [Double] {
        var activations = [inputData]
        for i in 0..<(layers.count - 1) {
            let weight = weights[i]
            let bias = biases[i]
            let activation = zip(activations.last!, weight).map { $0 * $1 }.reduce(0, +) + bias.first!
            activations.append(activation.tanh())
        }
        return activations.last!
    }
}

class DataGenerator {
    var data: [[Double]]

    init(size: Int, features: Int) {
        data = (0..<size).map { _ in
            Array(repeating: Double.random(in: -1...1), count: features)
        }
    }

    func generate() -> [[Double]] {
        return data
    }
}

class Trainer {
    var network: Network
    var dataGenerator: DataGenerator

    init(network: Network, dataGenerator: DataGenerator) {
        self.network = network
        self.dataGenerator = dataGenerator
    }

    func train() {
        while true {
            let data = dataGenerator.generate()
            for inputData in data {
                network.forward(inputData: inputData)
            }
        }
    }
}

func main() {
    let layers = [784, 128, 64, 10]
    let network = Network(layers: layers)
    let dataGenerator = DataGenerator(size: 1000, features: 784)
    let trainer = Trainer(network: network, dataGenerator: dataGenerator)
    trainer.train()
}

main()