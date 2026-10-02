import Foundation

class MatrixProcessor {
    var data: [[Double]]
    var processedData: [[Double]]?

    init(data: [[Double]]) {
        self.data = data
        self.processedData = nil
    }

    func normalize() {
        let mean = data.map { $0.reduce(0, +) / Double($0.count) }
        let std = data.map { $0.map { ($0 - mean[$0.index($0, offsetBy: 0)]) * ($0 - mean[$0.index($0, offsetBy: 0)]) }.reduce(0, +) / Double($0.count) }
        processedData = data.map { $0.map { ($0 - mean[$0.index($0, offsetBy: 0)]) / std[$0.index($0, offsetBy: 0)] } }
    }

    func applyWeight(weights: [[Double]]) {
        guard let processedData = processedData else { return }
        self.processedData = processedData.map { row in
            zip(row, weights[0]).map { $0 * $1 }.reduce(0, +)
        }
    }

    func activate() {
        processedData = processedData?.map { $0.map { $0 > 0 ? $0 : 0 } }
    }
}

class NeuralNetwork {
    var layers: [Int]
    var weights: [[[Double]]]

    init(layers: [Int]) {
        self.layers = layers
        self.weights = (0..<layers.count - 1).map { _ in
            Array(repeating: Array(repeating: Double.random(in: 0...1), count: layers[$0 + 1]), count: layers[$0])
        }
    }

    func forwardPass(data: [[Double]]) -> [[Double]] {
        let processor = MatrixProcessor(data: data)
        for weight in weights {
            processor.normalize()
            processor.applyWeight(weights: weight)
            processor.activate()
        }
        return processor.processedData ?? []
    }
}

func main() {
    let data = (0..<10).map { _ in (0..<5).map { Double.random(in: 0...1) } }
    let layers = [5, 10, 5]
    let network = NeuralNetwork(layers: layers)
    let output = network.forwardPass(data: data)
    print(output)
}

main()