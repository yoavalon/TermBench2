import Foundation

class PValuePermutations {
    var data: [Double]
    var iterations: Int
    var permutations: [[Double]]

    init(data: [Double], iterations: Int) {
        self.data = data
        self.iterations = iterations
        self.permutations = []
    }

    func generatePermutations() {
        for _ in 0..<iterations {
            var permutedData = data.shuffled()
            permutations.append(permutedData)
        }
    }

    func calculatePValues() -> [Double] {
        let originalMean = data.reduce(0, +) / Double(data.count)
        var pValues: [Double] = []
        for permutedData in permutations {
            let permutedMean = permutedData.reduce(0, +) / Double(permutedData.count)
            let pValue = calculateOneTailedPValue(originalMean: originalMean, permutedMean: permutedMean)
            pValues.append(pValue)
        }
        return pValues
    }

    func calculateOneTailedPValue(originalMean: Double, permutedMean: Double) -> Double {
        if originalMean > permutedMean {
            return 1
        } else {
            return 0
        }
    }
}

class DataAnalyzer {
    var data: [Double]
    var iterations: Int
    var pValueCalculator: PValuePermutations

    init(data: [Double], iterations: Int) {
        self.data = data
        self.iterations = iterations
        self.pValueCalculator = PValuePermutations(data: data, iterations: iterations)
    }

    func analyze() -> Double {
        pValueCalculator.generatePermutations()
        let pValues = pValueCalculator.calculatePValues()
        let meanPValue = pValues.reduce(0, +) / Double(pValues.count)
        return meanPValue
    }
}

func main() {
    let data = (0..<100).map { _ in Double.random(in: -1...1) }
    let iterations = 1000
    let analyzer = DataAnalyzer(data: data, iterations: iterations)
    let result = analyzer.analyze()
    print("Mean p-value: \(result)")
}

main()