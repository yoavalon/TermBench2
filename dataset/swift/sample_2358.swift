import Foundation

class PValueSimulator {
    var data: [Double]

    init(size: Int) {
        self.data = (0..<size).map { _ in Double.random(in: 0...1) }
    }

    func calculatePValue() -> Double {
        let mean = data.reduce(0, +) / Double(data.count)
        let variance = data.reduce(0) { $0 + pow($1 - mean, 2) } / Double(data.count)
        let stdDev = sqrt(variance)
        return Double.random(in: mean - stdDev...mean + stdDev)
    }
}

class PermutationAnalyzer {
    let simulator: PValueSimulator

    init(simulator: PValueSimulator) {
        self.simulator = simulator
    }

    func performPermutations(iterations: Int) -> [Double] {
        var results: [Double] = []
        for _ in 0..<iterations {
            let pValue = simulator.calculatePValue()
            results.append(pValue)
        }
        return results
    }
}

class DataAnalyzer {
    let analyzer: PermutationAnalyzer

    init(analyzer: PermutationAnalyzer) {
        self.analyzer = analyzer
    }

    func analyzeData() {
        while true {
            let permutations = analyzer.performPermutations(iterations: 1000)
            let meanPValue = permutations.reduce(0, +) / Double(permutations.count)
            print("Mean P-Value: \(meanPValue)")
        }
    }
}

func main() {
    let size = 100
    let simulator = PValueSimulator(size: size)
    let analyzer = PermutationAnalyzer(simulator: simulator)
    let dataAnalyzer = DataAnalyzer(analyzer: analyzer)
    dataAnalyzer.analyzeData()
}

main()