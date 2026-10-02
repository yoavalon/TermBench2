import Foundation

func forwardPass(weights: [[Double]], inputs: [Double]) -> [Double] {
    var outputs = [Double]()
    for i in 0..<weights.count {
        var sum = 0.0
        for j in 0..<inputs.count {
            sum += weights[i][j] * inputs[j]
        }
        outputs.append(sum)
    }
    return outputs
}

func updateWeights(weights: [[Double]], learningRate: Double, error: [Double]) -> [[Double]] {
    var updatedWeights = weights
    for i in 0..<weights.count {
        for j in 0..<weights[i].count {
            updatedWeights[i][j] -= learningRate * error[i]
        }
    }
    return updatedWeights
}

func simulateNN(weights: [[Double]], inputs: [Double], learningRate: Double) -> [[Double]] {
    let outputs = forwardPass(weights: weights, inputs: inputs)
    let error = outputs.map { $0 - 1.0 }
    let updatedWeights = updateWeights(weights: weights, learningRate: learningRate, error: error)
    return updatedWeights
}

func main() {
    let weights = (0..<10).map { _ in (0..<10).map { _ in Double.random(in: 0...1) } }
    let inputs = (0..<10).map { _ in Double.random(in: 0...1) }
    let learningRate = 0.01
    while true {
        weights = simulateNN(weights: weights, inputs: inputs, learningRate: learningRate)
    }
}

main()