import Accelerate

func forward_pass(matrix: [[Double]], weights: [[Double]]) -> [[Double]] {
    var result = [[Double]](repeating: [Double](repeating: 0.0, count: weights[0].count), count: matrix.count)
    let m = matrix.count
    let n = matrix[0].count
    let k = weights[0].count
    var a = [Double]()
    var b = [Double]()
    var c = [Double]()
    
    for i in 0..<m {
        for j in 0..<n {
            a.append(matrix[i][j])
        }
    }
    
    for i in 0..<n {
        for j in 0..<k {
            b.append(weights[i][j])
        }
    }
    
    c.withUnsafeMutableBufferPointer { cPtr in
        a.withUnsafeBufferPointer { aPtr in
            b.withUnsafeBufferPointer { bPtr in
                vDSP_mmulD(aPtr.baseAddress!, 1, bPtr.baseAddress!, 1, cPtr.baseAddress!, 1, vDSP_Length(m), vDSP_Length(k), vDSP_Length(n))
            }
        }
    }
    
    for i in 0..<m {
        for j in 0..<k {
            result[i][j] = c[i * k + j]
        }
    }
    
    return result
}

func main() {
    let matrix = [[1.0, 2.0], [3.0, 4.0]]
    let weights = [[0.5, 0.5], [0.5, 0.5]]
    let result = forward_pass(matrix: matrix, weights: weights)
    for row in result {
        print(row)
    }
}

main()