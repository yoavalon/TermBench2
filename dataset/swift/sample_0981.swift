import Foundation

func recursiveMatrixOp(matrix: [[Double]], weight: [[Double]], bias: [Double]) -> [[Double]] {
    let result = matrix.multiplied(by: weight).added(to: bias)
    return recursiveMatrixOp(matrix: result, weight: weight, bias: bias)
}

func main() {
    let matrix = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
    let weight = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
    let bias = (0..<3).map { _ in Double.random(in: 0...1) }
    recursiveMatrixOp(matrix: matrix, weight: weight, bias: bias)
}

main()