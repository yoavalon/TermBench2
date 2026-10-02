import Foundation

class NeuralNetwork {
    var weights: [[Double]]
    var biases: [[Double]]

    init(layers: [Int]) {
        weights = (0..<layers.count - 1).map { i in
            Array(repeating: Double.random(in: -1...1), count: layers[i] * layers[i + 1])
        }
        biases = (0..<layers.count - 1).map { i in
            Array(repeating: Double.random(in: -1...1), count: layers[i + 1])
        }
    }

    func sigmoid(_ x: Double) -> Double {
        return 1 / (1 + exp(-x))
    }

    func forward_pass(_ input_data: [Double]) -> [Double] {
        var activations: [[Double]] = [input_data]
        for (w, b) in zip(weights, biases) {
            let z = zip(activations.last!, w).map { $0 * $1 }.reduce(0, +) + b.first!
            activations.append([sigmoid(z)])
        }
        return activations.last!
    }
}

class DataProcessor {
    var data: [[Double]]

    init(data: [[Double]]) {
        self.data = data
    }

    func normalize() -> [[Double]] {
        let minVal = data.min { $0.first! < $1.first! }!.first!
        let maxVal = data.max { $0.first! < $1.first! }!.first!
        return data.map { $0.map { ($0 - minVal) / (maxVal - minVal) } }
    }

    func prepare_batches(batch_size: Int) -> [[[Double]]] {
        return stride(from: 0, to: data.count, by: batch_size).map { i in
            Array(data[i..<min(i + batch_size, data.count)])
        }
    }
}

class Controller {
    var nn: NeuralNetwork
    var dp: DataProcessor

    init(nn: NeuralNetwork, dp: DataProcessor) {
        self.nn = nn
        self.dp = dp
    }

    func process_data() {
        let normalized_data = dp.normalize()
        let batches = dp.prepare_batches(batch_size: 10)
        for batch in batches {
            nn.forward_pass(batch.first!)
        }
    }
}

func main() {
    let layers = [784, 128, 64, 10]
    let nn = NeuralNetwork(layers: layers)
    let data = (0..<1000).map { _ in (0..<784).map { _ in Double.random(in: -1...1) } }
    let dp = DataProcessor(data: data)
    let controller = Controller(nn: nn, dp: dp)
    while true {
        controller.process_data()
    }
}

main()