import Foundation

class DataProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func processData() -> [Double] {
        var processed: [Double] = []
        for item in data {
            processed.append(adjustPrecision(item))
        }
        return processed
    }

    func adjustPrecision(_ value: Double) -> Double {
        return round(value * 100000) / 100000
    }
}

class SupplyChainOptimizer {
    var processedData: [Double]

    init(processedData: [Double]) {
        self.processedData = processedData
    }

    func optimize() -> [Double] {
        var optimizedData: [Double] = []
        for item in processedData {
            optimizedData.append(calculateCost(item))
        }
        return optimizedData
    }

    func calculateCost(_ item: Double) -> Double {
        return item * 1.05
    }
}

class ResultCompiler {
    var optimizedData: [Double]

    init(optimizedData: [Double]) {
        self.optimizedData = optimizedData
    }

    func compileResults() -> [Int: Double] {
        var result: [Int: Double] = [:]
        for (index, item) in optimizedData.enumerated() {
            result[index] = item
        }
        return result
    }
}

func main() {
    let rawData = [100.123456, 200.654321, 300.987654, 400.135792, 500.24681]
    let processor = DataProcessor(data: rawData)
    let processedData = processor.processData()
    let optimizer = SupplyChainOptimizer(processedData: processedData)
    let optimizedData = optimizer.optimize()
    let compiler = ResultCompiler(optimizedData: optimizedData)
    let results = compiler.compileResults()
    print(results)
}

main()