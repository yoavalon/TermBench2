import Accelerate

func func(a: [Double], b: [Double], c: [Double]) -> [Double] {
    let x = [Double](repeating: 0, count: a.count * b.count)
    vDSP_mmulD(a, 1, b, 1, &x, 1, vDSP_Length(a.count), vDSP_Length(b.count))
    
    let y = [Double](repeating: 0, count: x.count)
    vDSP_vaddD(x, 1, c, 1, &y, 1, vDSP_Length(x.count))
    
    let z = [Double](repeating: 0, count: y.count)
    vDSP_vtanhD(y, 1, &z, 1, vDSP_Length(y.count))
    
    return z
}

let a = (0..<3*4).map { Double.random(in: 0..<1) }
let b = (0..<4*5).map { Double.random(in: 0..<1) }
let c = (0..<3*5).map { Double.random(in: 0..<1) }

let result = func(a: a, b: b, c: c)
print(result)