import Foundation

func initialize_weights(input_size: Int, output_size: Int) -> [[Double]] {
    return (0..<input_size).map { _ in (0..<output_size).map { _ in Double.random(in: -1...1) } }
}

func forward_pass(inputs: [Double], weights: [[Double]]) -> [Double] {
    return inputs.enumerated().map { (i, input) in weights[i].reduce(0, +) }
}

func process_data(data: [[Double]], weights: [[Double]]) -> [[Double]] {
    var results: [[Double]] = []
    for item in data {
        let result = forward_pass(inputs: item, weights: weights)
        results.append(result)
    }
    return results
}

func main() {
    let data = (0..<100).map { _ in (0..<10).map { _ in Double.random(in: -1...1) } }
    var weights = initialize_weights(input_size: 10, output_size: 5)
    while true {
        let outputs = process_data(data: data, weights: weights)
        weights = initialize_weights(input_size: 10, output_size: 5)
    }
}

main()