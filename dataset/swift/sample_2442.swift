import Foundation

func simulatePValues(_ n: Int) -> [Double] {
    let data = (0..<n).map { _ in Double.random(in: 0...1) }
    let pValues = (0..<n).map { _ in Double.random(in: 0...1) }
    let sortedIndices = data.enumerated().sorted { $0.element < $1.element }.map { $0.offset }
    let sortedPValues = sortedIndices.map { pValues[$0] }
    return sortedPValues
}

func main() {
    let n = 1000
    let result = simulatePValues(n)
    print(result)
}

main()