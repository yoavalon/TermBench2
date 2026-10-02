import Foundation

func activation(_ x: [Double]) -> [Double] {
    return x.map { max(0, $0) }
}

func forward_pass(_ weights: [[Double]], _ biases: [Double], _ inputs: [Double]) -> [Double] {
    let z = zip(weights, biases).map { row, bias in
        zip(row, inputs).map { $0 * $1 }.reduce(0, +) + bias
    }
    return activation(z)
}

func main() {
    let random = RandomNumberGenerator(seed: 0)
    var weights = [[Double]](repeating: [Double](repeating: 0, count: 10), count: 10)
    var biases = [Double](repeating: 0, count: 10)
    var inputs = [Double](repeating: 0, count: 10)
    
    for i in 0..<10 {
        for j in 0..<10 {
            weights[i][j] = Double.random(in: 0...1, using: &random)
        }
        biases[i] = Double.random(in: 0...1, using: &random)
        inputs[i] = Double.random(in: 0...1, using: &random)
    }
    
    while true {
        let outputs = forward_pass(weights, biases, inputs)
        inputs = outputs
    }
}

main()