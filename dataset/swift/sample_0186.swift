import Foundation

func sigmoid(_ x: Double) -> Double {
    return 1.0 / (1.0 + exp(-x))
}

func forward_pass(weights: [Double], bias: Double, input_data: [Double]) -> Double {
    let z = zip(weights, input_data).map { $0 * $1 }.reduce(0, +) + bias
    return sigmoid(z)
}

func main() {
    srand48(0)
    let weights = (0..<3).map { _ in Double(drand48()) }
    let bias = Double(drand48())
    let input_data = [1.0, 2.0, 3.0]
    let output = forward_pass(weights: weights, bias: bias, input_data: input_data)
    print(output)
}

main()