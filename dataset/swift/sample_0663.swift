import Foundation

func matrix_forward_pass(matrix: [[Double]], weights: [[Double]], bias: [Double], depth: Int) -> [[Double]] {
    if depth == 0 {
        return matrix
    }
    let dotProduct = matrix.map { row in
        zip(weights, row).map { $0 * $1 }.reduce([Double](repeating: 0, count: weights.count)) { $0 + $1 }
    }
    let result = dotProduct.map { row in
        zip(row, bias).map { $0 + $1 }
    }
    return matrix_forward_pass(matrix: result, weights: weights, bias: bias, depth: depth - 1)
}

func main() {
    let A = (0..<10).map { _ in (0..<5).map { _ in Double.random(in: 0...1) } }
    let W = (0..<5).map { _ in (0..<5).map { _ in Double.random(in: 0...1) } }
    let B = (0..<5).map { _ in Double.random(in: 0...1) }
    let depth = 3
    let result = matrix_forward_pass(matrix: A, weights: W, bias: B, depth: depth)
    print(result)
}

main()