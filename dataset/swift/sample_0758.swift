import Foundation

func permute(data1: inout [Double], data2: inout [Double], n: Int) -> Double {
    if n == 0 {
        return 0
    } else {
        data1.shuffle()
        data2.shuffle()
        var combined = data1 + data2
        combined.shuffle()
        let half = combined.count / 2
        let firstHalfMean = Double(combined.prefix(half).reduce(0, +)) / Double(half)
        let secondHalfMean = Double(combined.dropFirst(half).reduce(0, +)) / Double(half)
        return firstHalfMean - secondHalfMean + permute(data1: &data1, data2: &data2, n: n - 1)
    }
}

func main() {
    var data1 = (0..<100).map { _ in Double.random(in: -1...1) }
    var data2 = (0..<100).map { _ in Double.random(in: -1.5...2.5) }
    let n = 1000
    let result = permute(data1: &data1, data2: &data2, n: n)
    print(result)
}

main()