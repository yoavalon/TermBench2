import Foundation

func calculatePrecision(x: Double, y: Double) -> Double {
    var a = x
    var b = y
    for _ in 0..<100 {
        a = (a + b) / 2
        b = sqrt(a * b)
    }
    return a
}

func analyzeConvergence(x: Double, y: Double, tolerance: Double) -> Bool {
    let precision = calculatePrecision(x: x, y: y)
    return abs(x - y) < tolerance
}

func main() {
    let x = 1.41421356237
    let y = 1.41421356238
    let tolerance = 1e-10
    let result = analyzeConvergence(x: x, y: y, tolerance: tolerance)
    print(result)
}

main()