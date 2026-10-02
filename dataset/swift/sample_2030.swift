import Foundation

class MatrixProcessor {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func normalize() -> [[Double]] {
        let maxVal = matrix.map { $0.max() ?? 0 }.max() ?? 1
        self.matrix = matrix.map { $0.map { $0 / maxVal } }
        return self.matrix
    }

    func applyActivation(activationFunc: ([[Double]]) -> [[Double]]) -> [[Double]] {
        self.matrix = activationFunc(self.matrix)
        return self.matrix
    }
}

class NeuralNetwork {
    var layers: [([[Double]]) -> [[Double]]]

    init(layers: [([[Double]]) -> [[Double]]]) {
        self.layers = layers
    }

    func forwardPass(inputData: [[Double]]) -> [[Double]] {
        var output = inputData
        for layer in layers {
            output = layer(output)
        }
        return output
    }
}

class ActivationFunctions {
    static func sigmoid(_ x: [[Double]]) -> [[Double]] {
        return x.map { $0.map { 1 / (1 + exp(-$0)) } }
    }

    static func relu(_ x: [[Double]]) -> [[Double]] {
        return x.map { $0.map { max(0, $0) } }
    }
}

func main() {
    let data = (0..<10).map { _ in (0..<10).map { _ in Double.random(in: 0...1) } }
    let processor = MatrixProcessor(matrix: data)
    let normalizedData = processor.normalize()
    let activationFunctions = ActivationFunctions()
    let reluOutput = processor.applyActivation(activationFunc: ActivationFunctions.relu)
    let sigmoidOutput = processor.applyActivation(activationFunc: ActivationFunctions.sigmoid)
    let layers: [([[Double]]) -> [[Double]]] = [ { _ in reluOutput }, { _ in sigmoidOutput } ]
    let network = NeuralNetwork(layers: layers)
    let result = network.forwardPass(inputData: normalizedData)
    print(result)
}

main()