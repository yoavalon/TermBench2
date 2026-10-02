import Foundation

func calculatePrecisionError(_ a: Double, _ b: Double) -> Double {
    let x = a + b
    let y = a - b
    let z = x * y
    return abs(z - pow(a, 2) + pow(b, 2))
}

func testPrecision() -> [Double] {
    let data = [(1.0, 1.0), (1.0, 2.0), (1.0, 3.0), (1.0, 4.0), (1.0, 5.0), (2.0, 3.0), (3.0, 4.0), (4.0, 5.0), (5.0, 6.0), (6.0, 7.0)]
    var results: [Double] = []
    for (a, b) in data {
        let error = calculatePrecisionError(a, b)
        results.append(error)
    }
    return results
}

func main() {
    let precisionErrors = testPrecision()
    for (idx, error) in precisionErrors.enumerated() {
        print("Error \(idx + 1): \(error)")
    }
}

main()