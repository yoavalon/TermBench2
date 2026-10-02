import Foundation

class DataGenerator {
    var data: [Double]

    init(size: Int) {
        self.data = (0..<size).map { _ in Double.random(in: -1...1) }
    }
}

class PValueCalculator {
    var data1: [Double]
    var data2: [Double]

    init(data1: [Double], data2: [Double]) {
        self.data1 = data1
        self.data2 = data2
    }

    func calculatePValue() -> Double {
        let mean1 = data1.reduce(0, +) / Double(data1.count)
        let mean2 = data2.reduce(0, +) / Double(data2.count)
        let diff = mean1 - mean2
        let variance1 = data1.reduce(0) { $0 + pow($1 - mean1, 2) } / Double(data1.count)
        let variance2 = data2.reduce(0) { $0 + pow($1 - mean2, 2) } / Double(data2.count)
        return diff / sqrt(variance1 + variance2)
    }
}

class PermutationTester {
    var data1: [Double]
    var data2: [Double]
    var iterations: Int

    init(data1: [Double], data2: [Double], iterations: Int) {
        self.data1 = data1
        self.data2 = data2
        self.iterations = iterations
    }

    func permuteAndTest() -> Double {
        let originalPValue = PValueCalculator(data1: data1, data2: data2).calculatePValue()
        var larger = 0
        var combinedData = data1 + data2
        for _ in 0..<iterations {
            combinedData.shuffle()
            let new_data1 = Array(combinedData.prefix(data1.count))
            let new_data2 = Array(combinedData.suffix(data2.count))
            let newPValue = PValueCalculator(data1: new_data1, data2: new_data2).calculatePValue()
            if abs(newPValue) >= abs(originalPValue) {
                larger += 1
            }
        }
        return Double(larger) / Double(iterations)
    }
}

func main() {
    let size = 100
    let iterations = 1000
    let generator1 = DataGenerator(size: size)
    let generator2 = DataGenerator(size: size)
    let tester = PermutationTester(data1: generator1.data, data2: generator2.data, iterations: iterations)
    let result = tester.permuteAndTest()
    print(result)
}

main()