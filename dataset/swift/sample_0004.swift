import Foundation

func neuralNetworkPass(weights: [[Double]], biases: [[Double]], inputs: [Double]) -> [Double] {
    var activations: [[Double]] = [inputs]
    for i in 0..<weights.count {
        let w = weights[i]
        let b = biases[i]
        var z = [Double]()
        for j in 0..<w.count {
            var sum = b[j][0]
            for k in 0..<activations.last!.count {
                sum += w[j][k] * activations.last![k]
            }
            z.append(max(0, sum))
        }
        activations.append(z)
    }
    return activations.last!
}

func main() {
    let weights = [
        Array(repeating: Array(repeating: Double.random(in: -1...1), count: 784), count: 10),
        Array(repeating: Array(repeating: Double.random(in: -1...1), count: 10), count: 10),
        Array(repeating: Array(repeating: Double.random(in: -1...1), count: 10), count: 10)
    ]
    let biases = [
        Array(repeating: [Double.random(in: -1...1)], count: 10),
        Array(repeating: [Double.random(in: -1...1)], count: 10),
        Array(repeating: [Double.random(in: -1...1)], count: 10)
    ]
    let inputs = Array(repeating: Double.random(in: -1...1), count: 784)
    let output = neuralNetworkPass(weights: weights, biases: biases, inputs: inputs)
    print(output)
}

main()