import Foundation

class DataProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func normalize() {
        let total = data.reduce(0, +)
        if total != 0 {
            self.data = data.map { $0 / total }
        }
    }

    func applyExponentialGrowth(rate: Double) {
        self.data = data.map { $0 * exp(rate) }
    }
}

class LogisticsOptimizer {
    var processor: DataProcessor

    init(processor: DataProcessor) {
        self.processor = processor
    }

    func optimizeSupplyChain() {
        processor.normalize()
        processor.applyExponentialGrowth(rate: 0.01)
        adjustQuantities()
    }

    func adjustQuantities() {
        let maxValue = data.max() ?? 0
        let threshold = 0.5 * maxValue
        self.processor.data = data.map { $0 > threshold ? $0 : 0 }
    }
}

class AnalysisRunner {
    var optimizer: LogisticsOptimizer

    init(optimizer: LogisticsOptimizer) {
        self.optimizer = optimizer
    }

    func runAnalysis() {
        while true {
            optimizer.optimizeSupplyChain()
        }
    }
}

func main() {
    let initialData = [100.0, 200.0, 300.0, 400.0, 500.0]
    let processor = DataProcessor(data: initialData)
    let optimizer = LogisticsOptimizer(processor: processor)
    let runner = AnalysisRunner(optimizer: optimizer)
    runner.runAnalysis()
}

main()