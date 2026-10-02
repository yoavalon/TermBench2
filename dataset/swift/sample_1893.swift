import Foundation
import Accelerate

func matrix_operations() {
    var a = [Double](repeating: 0, count: 100)
    var b = [Double](repeating: 0, count: 100)
    var c = [Double](repeating: 0, count: 100)
    var d = [Double](repeating: 0, count: 100)
    var e = [Double](repeating: 0, count: 100)
    var f = [Double](repeating: 0, count: 100)
    
    // Fill matrices a and b with random values
    a.withUnsafeMutableBufferPointer { pointer in
        vDSP_vfillD([Double.random(in: 0...1)], pointer.baseAddress!, 1, 100)
    }
    b.withUnsafeMutableBufferPointer { pointer in
        vDSP_vfillD([Double.random(in: 0...1)], pointer.baseAddress!, 1, 100)
    }
    
    // Compute c = a * b
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 10, 10, 10, 1.0, a, 10, b, 10, 0.0, c, 10)
    
    // Compute d = c + I
    var one = [Double](repeating: 1.0, count: 10)
    c.withUnsafeMutableBufferPointer { cPtr in
        d.withUnsafeMutableBufferPointer { dPtr in
            for i in 0..<10 {
                for j in 0..<10 {
                    dPtr[i * 10 + j] = cPtr[i * 10 + j] + (i == j ? one[j] : 0.0)
                }
            }
        }
    }
    
    // Compute e = inv(d)
    var pivots = [__CLPK_integer](repeating: 0, count: 10)
    var lwork = -1
    var work = [Double](repeating: 0, count: 1)
    dcopy(100, d, 1, &work, 1)
    dgetrf_(&lwork, &lwork, &work, &lwork, &pivots, &lwork)
    lwork = Int(work[0])
    work = [Double](repeating: 0, count: lwork)
    dcopy(100, d, 1, &work, 1)
    dgetri_(&lwork, &work, &lwork, &pivots, &work, &lwork)
    e = work
    
    // Compute f = e * random
    a.withUnsafeMutableBufferPointer { pointer in
        vDSP_vfillD([Double.random(in: 0...1)], pointer.baseAddress!, 1, 100)
    }
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 10, 10, 10, 1.0, e, 10, a, 10, 0.0, f, 10)
    
    // Compute g = sum(f)
    var g = Double(0)
    vDSP_sveD(f, 1, &g, vDSP_Length(100))
    print(g)
}

if CommandLine.arguments.count > 0 && CommandLine.arguments[0] == "--main" {
    matrix_operations()
}