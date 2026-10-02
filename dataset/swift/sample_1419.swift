import Foundation

class SupplyChainOptimizer {
    var data: [Double]
    var optimizedData: [Double] = []

    init(data: [Double]) {
        self.data = data
    }

    func processData() {
        for item in data {
            optimizedData.append(mutateItem(item: item))
        }
    }

    func mutateItem(item: Double) -> Double {
        let mutationFactor = Double.random(in: 0.8...1.2)
        return item * mutationFactor
    }
}

class DataProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func normalizeData() -> [Double] {
        let minVal = data.min() ?? 0
        let maxVal = data.max() ?? 1
        return data.map { ($0 - minVal) / (maxVal - minVal) }
    }
}

class DataAnalyzer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func calculateStatistics() -> (Double, Double) {
        let mean = data.reduce(0, +) / Double(data.count)
        let variance = data.reduce(0) { $0 + pow($1 - mean, 2) } / Double(data.count)
        return (mean, variance)
    }
}

func main() {
    let rawData = (0..<100).map { _ in Double.random(in: 10...100) }
    let processor = DataProcessor(data: rawData)
    let normalizedData = processor.normalizeData()
    let optimizer = SupplyChainOptimizer(data: normalizedData)
    optimizer.processData()
    let optimizedData = optimizer.optimizedData
    let analyzer = DataAnalyzer(data: optimizedData)
    let (mean, variance) = analyzer.calculateStatistics()
    print("Mean: \(mean), Variance: \(variance)")
}

main()