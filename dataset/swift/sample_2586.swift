import Foundation

func sigmoid(_ x: Double) -> Double {
    return 1 / (1 + exp(-x))
}

func forwardPass(weights: [[Double]], bias: [Double], input_data: [[Double]]) -> [Double] {
    let layer1 = input_data.map { row in
        return zip(row, weights.map { $0.first! }).map { $0 * $1 }.reduce(0, +) + bias.first!
    }
    let output = layer1.map(sigmoid)
    return output
}

func main() {
    let weights = (0..<3).map { _ in (0..<4).map { Double.random(in: 0...1) } }
    let bias = (0..<4).map { Double.random(in: 0...1) }
    let input_data = (0..<4).map { _ in (0..<3).map { Double.random(in: 0...1) } }
    let result = forwardPass(weights: weights, bias: bias, input_data: input_data)
    print(result)
}

main()