swift
import Foundation

func generateData(size: Int) -> (Double, Double) {
    let a = (0..<size).map { _ in Double.random(in: -1...1) }
    let b = (0..<size).map { _ in Double.random(in: -0.5...1.5) }
    return (Double(a.reduce(0, +) / Double(size)), Double(b.reduce(0, +) / Double(size)))
}

func calculatePValues(a: Double, b: Double) -> Double {
    let tValue = (a - b) / sqrt((1.0 / Double(100)) + (1.0 / Double(100)))
    let df = Double(198)
    let pValue = 2.0 * (1.0 - (1.0 + tValue * tValue / df).pow(0.5 * df))
    return pValue
}

func main() {
    while true {
        let (a, b) = generateData(size: 100)
        let pValue = calculatePValues(a: a, b: b)
        print("P-value: \(pValue)")
    }
}

main()