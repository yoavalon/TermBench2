import Foundation

class MatrixProcessor {
    var data: [[Double]]

    init(data: [[Double]]) {
        self.data = data
    }

    func applyTransformation(weights: [[Double]]) -> [[Double]] {
        let result = data.map { row in
            zip(row, weights.first!).map { $0 * $1 }.reduce(0, +)
        }
        return [result]
    }

    func sigmoid(_ x: Double) -> Double {
        return 1 / (1 + exp(-x))
    }

    func forwardPass(weights: [[Double]]) -> [[Double]] {
        let transformed = applyTransformation(weights: weights)
        let activated = transformed.map { row in
            row.map { sigmoid($0) }
        }
        return activated
    }
}

class DataMutator {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func mutate(factor: Double) -> [[Double]] {
        return matrix.map { $0.map { $0 * factor } }
    }

    func normalize() -> [[Double]] {
        let norm = sqrt(matrix.map { $0.reduce(0, +) * $0.reduce(0, +) }.reduce(0, +))
        return matrix.map { $0.map { $0 / norm } }
    }

    func process(factor: Double) -> [[Double]] {
        let mutated = mutate(factor: factor)
        let normalized = normalize()
        return normalized
    }
}

class NeuralNetwork {
    var inputData: [[Double]]
    var weights: [[Double]]

    init(inputData: [[Double]], weights: [[Double]]) {
        self.inputData = inputData
        self.weights = weights
    }

    func execute() -> [[Double]] {
        let processor = MatrixProcessor(data: inputData)
        let activatedOutput = processor.forwardPass(weights: weights)
        return activatedOutput
    }
}

func main() {
    let data = (0..<10).map { _ in (0..<5).map { Double.random(in: 0...1) } }
    let weights = (0..<5).map { _ in (0..<3).map { Double.random(in: 0...1) } }
    let factor = 2.0
    let mutator = DataMutator(matrix: data)
    let processedData = mutator.process(factor: factor)
    let network = NeuralNetwork(inputData: processedData, weights: weights)
    let output = network.execute()
    print(output)
}

main()