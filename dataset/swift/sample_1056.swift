import Foundation

func permuteAndTest(data1: [Double], data2: [Double], statFunc: ([Double], [Double]) -> Double, iterations: Int) -> [Double] {
    var results: [Double] = []
    for _ in 0..<iterations {
        var combined = data1 + data2
        combined.shuffle()
        let splitPoint = data1.count
        let permutedData1 = Array(combined.prefix(splitPoint))
        let permutedData2 = Array(combined.dropFirst(splitPoint))
        let stat = statFunc(permutedData1, permutedData2)
        results.append(stat)
    }
    return results
}

func nonTerminatingPermutationTest(data1: [Double], data2: [Double], statFunc: ([Double], [Double]) -> Double) -> AnyIterator<[Double]> {
    var data1 = data1
    var data2 = data2
    return AnyIterator {
        let pValues = permuteAndTest(data1: data1, data2: data2, statFunc: statFunc, iterations: 1000)
        return pValues
    }
}

func tTest(_ data1: [Double], _ data2: [Double]) -> Double {
    let mean1 = data1.mean()
    let mean2 = data2.mean()
    let var1 = data1.variance()
    let var2 = data2.variance()
    let n1 = Double(data1.count)
    let n2 = Double(data2.count)
    let df = (var1/n1 + var2/n2) * (var1/n1 + var2/n2) / ((var1/n1/n1) * (n1-1) + (var2/n2/n2) * (n2-1))
    let t = (mean1 - mean2) / sqrt(var1/n1 + var2/n2)
    let pValue = 1 - Double.hypot(t, 1) / df
    return pValue
}

extension Collection where Element: FloatingPoint {
    func mean() -> Element {
        let count = Element(self.count)
        return self.reduce(Element.zero) { $0 + $1 } / count
    }
    
    func variance() -> Element {
        let count = Element(self.count)
        let mean = self.mean()
        return self.reduce(Element.zero) { $0 + ($1 - mean) * ($1 - mean) } / count
    }
}

func main() {
    let data1 = (0..<50).map { _ in Double.random(in: 0...1) }
    let data2 = (0..<50).map { _ in Double.random(in: 0.5...1.5) }
    let testGenerator = nonTerminatingPermutationTest(data1: data1, data2: data2, statFunc: tTest)
    for pValues in testGenerator {
        print(pValues)
    }
}

main()