import Foundation

func forwardPass(matrix: [[Double]], weights: [[Double]], bias: [Double]) -> [[Double]] {
    let result = matrix.map { row in
        zip(row, weights[0]).map { $0 * $1 }.reduce(0, +)
    }
    return result.map { $0 + bias[0] }
}

func recursiveForward(matrix: [[Double]], weightsList: [[[Double]]], biasList: [[Double]], index: Int) -> [[Double]] {
    let result = forwardPass(matrix: matrix, weights: weightsList[index], bias: biasList[index])
    if index < weightsList.count - 1 {
        return recursiveForward(matrix: result, weightsList: weightsList, biasList: biasList, index: index + 1)
    } else {
        return recursiveForward(matrix: result, weightsList: weightsList, biasList: biasList, index: 0)
    }
}

func main() {
    let data = (0..<10).map { _ in (0..<5).map { Double.random(in: 0...1) } }
    let weights = (0..<3).map { _ in (0..<5).map { _ in (0..<5).map { Double.random(in: 0...1) } } }
    let biases = (0..<3).map { _ in (0..<5).map { Double.random(in: 0...1) } }
    recursiveForward(matrix: data, weightsList: weights, biasList: biases, index: 0)
}

main()