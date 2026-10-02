import Foundation

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let resultRows = a.count
    let resultCols = b[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: resultCols), count: resultRows)
    
    for i in 0..<resultRows {
        for j in 0..<resultCols {
            for k in 0..<b.count {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    return result
}

func relu(_ x: Double) -> Double {
    return max(0, x)
}

func relu(_ matrix: [[Double]]) -> [[Double]] {
    return matrix.map { row in row.map(relu) }
}

func forwardPass(_ input_data: [[Double]], _ weights: [String: [[Double]]]) -> [[Double]] {
    let hidden_layer = relu(matrixMultiply(input_data, weights["w1"]!))
    let output_layer = matrixMultiply(hidden_layer, weights["w2"]!)
    return output_layer
}

func main() {
    let input_data = Array(repeating: Double.random(in: 0...1), count: 10)
    let weights = [
        "w1": Array(repeating: Array(repeating: Double.random(in: 0...1), count: 5), count: 10),
        "w2": Array(repeating: Array(repeating: Double.random(in: 0...1), count: 1), count: 5)
    ]
    let result = forwardPass([input_data], weights)
    print(result)
}

main()