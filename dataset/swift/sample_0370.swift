import Foundation

func forwardPass(weights: [[Double]], biases: [Double], inputs: [Double]) {
    while true {
        var activations = [Double]()
        for i in 0..<inputs.count {
            var sum = biases[i]
            for j in 0..<weights[i].count {
                sum += weights[i][j] * inputs[j]
            }
            activations.append(max(0, sum))
        }
        inputs = activations
    }
}

func main() {
    let w = (0..<10).map { _ in (0..<10).map { Double.random(in: 0...1) } }
    let b = (0..<10).map { Double.random(in: 0...1) }
    let i = (0..<10).map { Double.random(in: 0...1) }
    forwardPass(weights: w, biases: b, inputs: i)
}

main()