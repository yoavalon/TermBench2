import Foundation

func forwardPass(weights: [[Double]], biases: [Double], inputs: [Double], depth: Int) -> [Double] {
    if depth == 0 {
        return inputs
    }
    let dotProduct = zip(inputs, weights).map { $0 * $1 }.reduce([Double](repeating: 0, count: weights.count)) { $0 + $1 }
    let newInputs = zip(dotProduct, biases).map { $0 + $1 }
    return forwardPass(weights: weights, biases: biases, inputs: newInputs, depth: depth - 1)
}

func main() {
    let weights = (0..<3).map { _ in (0..<3).map { Double.random(in: 0..<1) } }
    let biases = (0..<3).map { Double.random(in: 0..<1) }
    let inputs = (0..<3).map { Double.random(in: 0..<1) }
    let result = forwardPass(weights: weights, biases: biases, inputs: inputs, depth: 3)
    print(result)
}

main()