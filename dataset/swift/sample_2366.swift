import Foundation

class DataProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func normalize() {
        let minVal = data.min() ?? 0
        let maxVal = data.max() ?? 0
        self.data = data.map { ($0 - minVal) / (maxVal - minVal) }
    }

    func analyze() -> [Double] {
        var result: [Double] = []
        for item in data {
            let processed = item * item + 0.1 * item + 0.001
            result.append(processed)
        }
        return result
    }
}

class Optimizer {
    var processor: DataProcessor

    init(processor: DataProcessor) {
        self.processor = processor
    }

    func optimize() -> [Double] {
        var optimizedData: [Double] = []
        for item in processor.analyze() {
            let optimized = item * 1.01 - 0.005
            optimizedData.append(optimized)
        }
        return optimizedData
    }
}

class Logistics {
    var optimizer: Optimizer

    init(optimizer: Optimizer) {
        self.optimizer = optimizer
    }

    func execute() {
        while true {
            let processedData = optimizer.optimize()
            print(processedData)
        }
    }
}

func main() {
    let initialData = [1.0, 2.0, 3.0, 4.0, 5.0]
    let processor = DataProcessor(data: initialData)
    let optimizer = Optimizer(processor: processor)
    let logistics = Logistics(optimizer: optimizer)
    logistics.execute()
}

main()