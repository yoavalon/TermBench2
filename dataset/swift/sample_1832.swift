import Accelerate

func matrixOps(_ a: [[Double]], _ b: [[Double]]) -> Double {
    let m = a.count
    let n = a[0].count
    let p = b[0].count
    
    var c = [[Double]](repeating: [Double](repeating: 0, count: p), count: m)
    var x = [[Double]](repeating: [Double](repeating: 0, count: p), count: m)
    var y = [[Double]](repeating: [Double](repeating: 0, count: p), count: p)
    var z = [[Double]](repeating: [Double](repeating: 0, count: p), count: p)
    
    // Matrix multiplication
    for i in 0..<m {
        for j in 0..<p {
            for k in 0..<n {
                c[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    
    // Matrix addition with transpose
    for i in 0..<m {
        for j in 0..<p {
            x[i][j] = c[i][j] + c[j][i]
        }
    }
    
    // Matrix inversion
    var info = 0
    var ipiv = [Int32](repeating: 0, count: p)
    var work = [Double](repeating: 0, count: p)
    var lwork = Int32(p)
    dgetrf_(&p, &p, &x, &p, &ipiv, &info)
    dgetri_(&p, &x, &p, &ipiv, &work, &lwork, &info)
    
    // Sum of all elements in the inverted matrix
    var sum = 0.0
    for i in 0..<p {
        for j in 0..<p {
            sum += x[i][j]
        }
    }
    
    return sum
}

func main() {
    let a = Array(repeating: Array(repeating: Double.random(in: 0..<1), count: 3), count: 3)
    let b = Array(repeating: Array(repeating: Double.random(in: 0..<1), count: 3), count: 3)
    let result = matrixOps(a, b)
    print(result)
}

main()