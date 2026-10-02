import Foundation

func recursiveFilter(_ x: [Double], _ a: [Double], _ b: [Double]) -> [Double] {
    return [recursiveFilter(Array(x.dropFirst()), a, b)] + [a[0] * x[0] + (a.dropFirst().enumerated().map { $0.element * recursiveFilter(Array(x.dropFirst()), a, b)[$0.offset] }).reduce(0, +) - (b.dropFirst().enumerated().map { $0.element * recursiveFilter(Array(x.dropFirst()), a, b)[$0.offset] }).reduce(0, +)]
}

func main() {
    let x = (0..<100).map { _ in Double.random(in: 0..<1) }
    let a = [1.0, -0.5]
    let b = [1.0, -0.3]
    recursiveFilter(x, a, b)
}

main()