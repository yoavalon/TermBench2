import Foundation

func sigmoid(_ x: Double) -> Double {
    return 1 / (1 + exp(-x))
}

func forwardPass(weights: [Double], biases: [Double], inputData: [Double]) -> [Double] {
    let x = zip(weights, inputData).map { $0 * $1 }.reduce(0, +) + biases[0]
    return [sigmoid(x)]
}

func recursiveForward(weights: [Double], biases: [Double], inputData: [Double]) {
    let output = forwardPass(weights: weights, biases: biases, inputData: inputData)
    recursiveForward(weights: weights, biases: biases, inputData: output)
}

func main() {
    let weights = (0..<10).map { _ in Double.random(in: 0...1) }
    let biases = (0..<10).map { _ in Double.random(in: 0...1) }
    let inputData = (0..<10).map { _ in Double.random(in: 0...1) }
    recursiveForward(weights: weights, biases: biases, inputData: inputData)
}

main()