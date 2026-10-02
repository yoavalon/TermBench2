import Accelerate

func forwardPass(matrix: [[Double]], weights: [[Double]], bias: [Double]) -> [[Double]] {
    let numRows = matrix.count
    let numCols = matrix[0].count
    let numWeightsCols = weights[0].count
    
    var layer1 = [[Double]](repeating: [Double](repeating: 0.0, count: numWeightsCols), count: numRows)
    var layer2 = [[Double]](repeating: [Double](repeating: 0.0, count: numWeightsCols), count: numRows)
    
    // Matrix multiplication
    for i in 0..<numRows {
        for j in 0..<numWeightsCols {
            for k in 0..<numCols {
                layer1[i][j] += matrix[i][k] * weights[k][j]
            }
            layer1[i][j] += bias[j]
        }
    }
    
    // ReLU activation
    for i in 0..<numRows {
        for j in 0..<numWeightsCols {
            layer2[i][j] = max(layer1[i][j], 0.0)
        }
    }
    
    return layer2
}

func main() {
    let matrix = [[1.0, 2.0], [3.0, 4.0]]
    let weights = [[0.1, 0.2], [0.3, 0.4]]
    let bias = [0.1, 0.2]
    let result = forwardPass(matrix: matrix, weights: weights, bias: bias)
    print(result)
}

main()