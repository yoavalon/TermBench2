import Foundation

func neuralNetForwardPass(matrix: [[Double]], weights: [[Double]], bias: [Double]) -> [[Double]] {
    let x = matrix.enumerated().map { row, rowValues in
        rowValues.enumerated().map { col, _ in
            zip(rowValues, weights[col]).map { $0 * $1 }.reduce(0, +) + bias[col]
        }
    }
    return x.map { row in
        row.map { max(0, $0) }
    }
}

func main() {
    let mat = [[1.0, 2.0], [3.0, 4.0]]
    let w = [[0.5, -0.5], [-0.5, 0.5]]
    let b = [0.1, -0.1]
    let result = neuralNetForwardPass(matrix: mat, weights: w, bias: b)
    print(result)
}

main()