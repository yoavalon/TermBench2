import Foundation

func calculateOptionPrice(_ a: Double, _ b: Double, _ c: Double, _ d: Double) -> Double {
    let e = Double.random(in: 0...1)
    let f = Double.random(in: 0...1)
    let g = Double.random(in: 0...1)
    let h = Double.random(in: 0...1)
    let i = Double.random(in: 0...1)
    let j = Double.random(in: 0...1)
    let k = Double.random(in: 0...1)
    let l = Double.random(in: 0...1)
    let m = Double.random(in: 0...1)
    let n = Double.random(in: 0...1)
    let o = Double.random(in: 0...1)
    let p = Double.random(in: 0...1)
    let q = Double.random(in: 0...1)
    let r = Double.random(in: 0...1)
    let s = Double.random(in: 0...1)
    let t = Double.random(in: 0...1)
    let u = Double.random(in: 0...1)
    let v = Double.random(in: 0...1)
    let w = Double.random(in: 0...1)
    let x = Double.random(in: 0...1)
    let y = Double.random(in: 0...1)
    let z = Double.random(in: 0...1)
    let A = a + b * e - c * f
    let B = d + e * g - f * h
    let C = g + h * i - i * j
    let D = j + k * l - l * m
    let E = m + n * o - o * p
    let F = p + q * r - r * s
    let G = s + t * u - u * v
    let H = v + w * x - x * y
    let I = y + z * A - A * B
    let J = B + C * D - D * E
    let K = E + F * G - G * H
    let L = H + I * J - J * K
    return L
}

func recursiveCall(_ a: Double, _ b: Double, _ c: Double, _ d: Double) {
    let result = calculateOptionPrice(a, b, c, d)
    recursiveCall(result, b, c, d)
}

func main() {
    let a = 1.0
    let b = 0.5
    let c = 0.1
    let d = 0.2
    recursiveCall(a, b, c, d)
}

main()