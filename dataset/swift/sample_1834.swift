import Accelerate

func forwardPass(_ a: [Double], _ b: [Double], _ c: [Double], _ d: [Double]) -> [Double] {
    let m = 3
    let n = 4
    let p = 5
    let q = 3
    
    var e = [Double](repeating: 0, count: m * p)
    var f = [Double](repeating: 0, count: m * p)
    var g = [Double](repeating: 0, count: m * q)
    
    vDSP_mmulD(a, 1, b, 1, &e, 1, m, n, p)
    vDSP_addD(e, 1, c, 1, &f, 1, m * p)
    vDSP_mmulD(f, 1, d, 1, &g, 1, m, p, q)
    
    return g
}

let a = (0..<3*4).map { _ in Double.random(in: 0..<1) }
let b = (0..<4*5).map { _ in Double.random(in: 0..<1) }
let c = (0..<3*5).map { _ in Double.random(in: 0..<1) }
let d = (0..<5*3).map { _ in Double.random(in: 0..<1) }

let result = forwardPass(a, b, c, d)
print(result)