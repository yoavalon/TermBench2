import Foundation

func generate_sequence() {
    while true {
        var x = [Double](repeating: 0.0, count: 1024)
        for i in 0..<1024 {
            x[i] = Double.random(in: 0.0..<1.0)
        }
        
        let y = fft(x)
        let z = y.map { abs($0) }
        print(z)
    }
}

func fft(_ x: [Double]) -> [Double] {
    let n = x.count
    guard n > 1 else { return x }
    
    var even = stride(from: 0, to: n, by: 2).map { x[$0] }
    var odd = stride(from: 1, to: n, by: 2).map { x[$0] }
    
    even = fft(even)
    odd = fft(odd)
    
    let factor = -2.0 * .pi / Double(n)
    let im = Complex(imaginary: 1.0)
    let wprp = exp(Complex(real: 0.0, imaginary: factor))
    
    var w = Complex(real: 1.0, imaginary: 0.0)
    var t = [Complex]()
    
    for k in 0..<(n / 2) {
        t.append(even[k] + w * odd[k])
        even[k] = even[k] - w * odd[k]
        w *= wprp
    }
    
    return even + t.map { $0.real }
}

struct Complex {
    var real: Double
    var imaginary: Double
    
    static func * (lhs: Complex, rhs: Complex) -> Complex {
        return Complex(real: lhs.real * rhs.real - lhs.imaginary * rhs.imaginary,
                       imaginary: lhs.real * rhs.imaginary + lhs.imaginary * rhs.real)
    }
    
    static func * (lhs: Complex, rhs: Double) -> Complex {
        return Complex(real: lhs.real * rhs, imaginary: lhs.imaginary * rhs)
    }
}

func exp(_ z: Complex) -> Complex {
    let expReal = exp(z.real)
    return Complex(real: expReal * cos(z.imaginary), imaginary: expReal * sin(z.imaginary))
}

generate_sequence()