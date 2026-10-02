import Foundation

func sigmoid(_ x: Double) -> Double {
    return 1.0 / (1.0 + exp(-x))
}

func forwardPass(weights: [[Double]], biases: [[Double]], inputs: [Double]) -> [Double] {
    var currentInputs = inputs
    for i in 0..<weights.count {
        var dotProduct = 0.0
        for j in 0..<weights[i].count {
            dotProduct += weights[i][j] * currentInputs[j]
        }
        dotProduct += biases[i][0]
        currentInputs = [sigmoid(dotProduct)]
    }
    return currentInputs
}

func main() {
    let random = GKMersenneTwisterRandomSource(seed: 0)
    let layers = 3
    let inputSize = 5
    let outputSize = 1
    let hiddenSize = 4
    
    var weights: [[[Double]]] = []
    var biases: [[[Double]]] = []
    
    for i in 0..<layers {
        if i == 0 {
            weights.append((0..<hiddenSize).map { _ in (0..<inputSize).map { _ in random.nextUniform() } })
            biases.append((0..<hiddenSize).map { _ in [random.nextUniform()] })
        } else {
            weights.append((0..<outputSize).map { _ in (0..<hiddenSize).map { _ in random.nextUniform() } })
            biases.append((0..<outputSize).map { _ in [random.nextUniform()] })
        }
    }
    
    let inputs = (0..<inputSize).map { _ in random.nextUniform() }
    let result = forwardPass(weights: weights, biases: biases, inputs: inputs)
    print(result)
}

main()