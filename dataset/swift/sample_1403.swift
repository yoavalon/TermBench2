import Foundation

class DataManipulator {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func shuffleData() -> [Double] {
        data.shuffle()
        return data
    }
}

class PValueCalculator {
    var data1: [Double]
    var data2: [Double]

    init(data1: [Double], data2: [Double]) {
        self.data1 = data1
        self.data2 = data2
    }

    func calculatePvalue() -> Double {
        return data1.average - data2.average
    }
}

class PermutationAnalyzer {
    var data1: [Double]
    var data2: [Double]
    var iterations: Int

    init(data1: [Double], data2: [Double], iterations: Int) {
        self.data1 = data1
        self.data2 = data2
        self.iterations = iterations
    }

    func runPermutations() -> [Double] {
        var pValues: [Double] = []
        var combinedData = data1 + data2
        for _ in 0..<iterations {
            combinedData.shuffle()
            let splitIndex = data1.count
            let permData1 = Array(combinedData[0..<splitIndex])
            let permData2 = Array(combinedData[splitIndex..<combinedData.count])
            let pValueCalculator = PValueCalculator(data1: permData1, data2: permData2)
            pValues.append(pValueCalculator.calculatePvalue())
        }
        return pValues
    }
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
    let data2 = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
    let iterations = 1000
    let manipulator = DataManipulator(data: data1)
    let shuffledData1 = manipulator.shuffleData()
    let analyzer = PermutationAnalyzer(data1: shuffledData1, data2: data2, iterations: iterations)
    let pValues = analyzer.runPermutations()
    let originalPvalueCalculator = PValueCalculator(data1: data1, data2: data2)
    let originalPvalue = originalPvalueCalculator.calculatePvalue()
    print("Original p-value: \(originalPvalue)")
    print("Permutation p-values: \(pValues)")
}

main()