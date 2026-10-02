import Foundation

class DataGenerator {
    var size: Int
    var data: [Double]

    init(size: Int) {
        self.size = size
        self.data = (0..<size).map { _ in Double.random(in: 0...1) }
    }

    func generate() -> [Double] {
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

    func calculate() -> Double {
        return permutationTest(x: data1, y: data2)
    }

    func permutationTest(x: [Double], y: [Double]) -> Double {
        let combined = x + y
        let observedDiff = abs(x.reduce(0, +) - y.reduce(0, +))
        var larger = 0
        for _ in 0..<10000 {
            var combinedShuffled = combined.shuffled()
            let splitPoint = x.count
            let permX = Array(combinedShuffled.prefix(splitPoint))
            let permY = Array(combinedShuffled.dropFirst(splitPoint))
            let permDiff = abs(permX.reduce(0, +) - permY.reduce(0, +))
            if permDiff >= observedDiff {
                larger += 1
            }
        }
        return Double(larger) / 10000
    }
}

class RecursiveAnalysis {
    var generator: DataGenerator
    var calculator: PValueCalculator

    init(generator: DataGenerator, calculator: PValueCalculator) {
        self.generator = generator
        self.calculator = calculator
    }

    func analyze() {
        let data1 = generator.generate()
        let data2 = generator.generate()
        let pValue = calculator.calculate()
        print("P-value: \(pValue)")
        analyze()
    }
}

func main() {
    let dataGen = DataGenerator(size: 100)
    let pValueCalc = PValueCalculator(data1: [], data2: [])
    let analysis = RecursiveAnalysis(generator: dataGen, calculator: pValueCalc)
    analysis.analyze()
}

main()