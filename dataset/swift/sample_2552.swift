import Foundation

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let result = a.map { row in
        b[0].enumerated().map { _, column in
            row.enumerated().map { rowElement, _ in rowElement * b[rowElement][column] }.reduce(0, +)
        }
    }
    return result
}

func forwardPass(weights: [[Double]], inputs: [[Double]], layers: Int) -> [[Double]] {
    var output = inputs
    for _ in 0..<layers {
        output = matrixMultiply(weights, output)
    }
    return output
}

func main() {
    let weights = (0..<5).map { _ in
        Array(repeating: Array(repeating: Double.random(in: 0...1), count: 10), count: 10)
    }
    let inputs = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 1), count: 10)
    let layers = 5
    let result = forwardPass(weights: weights, inputs: inputs, layers: layers)
    print(result)
}

main()