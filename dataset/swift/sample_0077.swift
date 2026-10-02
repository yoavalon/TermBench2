import Accelerate

func matrixOp(x: [Double], w: [Double], b: [Double]) -> [Double] {
    let m = 3
    let n = 4
    let p = 5
    
    var z = [Double](repeating: 0.0, count: m * p)
    var a = [Double](repeating: 0.0, count: m * p)
    
    let xPtr = x.withUnsafeBufferPointer { $0.baseAddress! }
    let wPtr = w.withUnsafeBufferPointer { $0.baseAddress! }
    let zPtr = z.withUnsafeMutableBufferPointer { $0.baseAddress! }
    
    // Perform matrix multiplication
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, p, n, 1.0, xPtr, n, wPtr, p, 0.0, zPtr, p)
    
    // Add bias
    for i in 0..<m {
        for j in 0..<p {
            z[i * p + j] += b[j]
        }
    }
    
    // Apply ReLU activation
    for i in 0..<z.count {
        a[i] = max(0, z[i])
    }
    
    return a
}

func main() {
    let x = (0..<12).map { _ in Double.random(in: 0...1) }
    let w = (0..<20).map { _ in Double.random(in: 0...1) }
    let b = (0..<5).map { _ in Double.random(in: 0...1) }
    
    let result = matrixOp(x: x, w: w, b: b)
    print(result)
}

main()