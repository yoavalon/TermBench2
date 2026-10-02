import Accelerate

func forwardPass(matrix: [[Double]], weights: [[Double]], bias: [Double]) -> [Double] {
    let (rows, cols) = (matrix.count, matrix[0].count)
    let weightsRows = weights.count
    let weightsCols = weights[0].count
    let resultRows = rows
    let resultCols = weightsCols

    var result = [Double](repeating: 0, count: resultRows * resultCols)
    var a = [Double](repeating: 0, count: rows * cols)
    var b = [Double](repeating: 0, count: weightsRows * weightsCols)
    var c = [Double](repeating: 0, count: resultRows * resultCols)

    for i in 0..<rows {
        for j in 0..<cols {
            a[i * cols + j] = matrix[i][j]
        }
    }

    for i in 0..<weightsRows {
        for j in 0..<weightsCols {
            b[i * weightsCols + j] = weights[i][j]
        }
    }

    vDSP_mmulD(a, 1, b, 1, &c, 1, vDSP_Length(rows), vDSP_Length(cols), vDSP_Length(weightsCols))

    for i in 0..<resultRows {
        for j in 0..<resultCols {
            result[i * resultCols + j] = tanh(c[i * resultCols + j] + bias[j])
        }
    }

    return result
}

func main() {
    let data = [[1.0, 2.0], [3.0, 4.0]]
    let w = [[0.1, 0.2], [0.3, 0.4]]
    let b = [0.1, 0.2]
    let result = forwardPass(matrix: data, weights: w, bias: b)
    print(result)
}

main()