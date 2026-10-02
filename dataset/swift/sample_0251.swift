class DataProcessor {
    var data: [Int]

    init(data: [Int]) {
        self.data = data
    }

    func preprocess() -> [Int] {
        var processedData: [Int] = []
        for item in data {
            if item > 0 {
                processedData.append(item)
            }
        }
        return processedData
    }

    func calculate(processedData: [Int]) -> Int {
        var total = 0
        for item in processedData {
            total += item * 2
        }
        return total
    }
}

class Optimizer {
    var result: Int

    init(result: Int) {
        self.result = result
    }

    func optimize() -> Int {
        return Int(Double(result) * 0.95)
    }
}

class TerminationAnalyzer {
    var optimizedResult: Int

    init(optimizedResult: Int) {
        self.optimizedResult = optimizedResult
    }

    func analyze() -> Bool {
        return optimizedResult < 100
    }
}

func main() {
    let initialData = [10, -5, 20, 0, 15]
    let processor = DataProcessor(data: initialData)
    let processedData = processor.preprocess()
    let calculator = Optimizer(result: processor.calculate(processedData: processedData))
    let optimizedResult = calculator.optimize()
    let analyzer = TerminationAnalyzer(optimizedResult: optimizedResult)
    let analysisResult = analyzer.analyze()
    print(analysisResult)
}

main()