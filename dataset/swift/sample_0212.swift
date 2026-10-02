import Foundation

class SignalProcessor {
    
    var data: [Double]
    var length: Int
    
    init(data: [Double]) {
        self.data = data
        self.length = data.count
    }
    
    func applyFilter(filterCoefficients: [Double]) -> [Double] {
        let filteredData = data.convolve(with: filterCoefficients, mode: .same)
        return filteredData
    }
}

class BoundaryHandler {
    
    var signalProcessor: SignalProcessor
    
    init(signalProcessor: SignalProcessor) {
        self.signalProcessor = signalProcessor
    }
    
    func processData() -> [Double] {
        let filterCoefficients = [0.1, 0.2, 0.3, 0.2, 0.1]
        let processedData = signalProcessor.applyFilter(filterCoefficients: filterCoefficients)
        return processedData
    }
}

class DataAnalyzer {
    
    var boundaryHandler: BoundaryHandler
    
    init(boundaryHandler: BoundaryHandler) {
        self.boundaryHandler = boundaryHandler
    }
    
    func analyze() -> (Double, Double, Double) {
        let data = boundaryHandler.processData()
        let meanValue = data.mean()
        let maxValue = data.max() ?? 0
        let minValue = data.min() ?? 0
        return (meanValue, maxValue, minValue)
    }
}

extension Array where Element == Double {
    func convolve(with filterCoefficients: [Double], mode: String) -> [Double] {
        let filterLength = filterCoefficients.count
        let resultLength = self.count
        var result = [Double](repeating: 0.0, count: resultLength)
        
        for i in 0..<resultLength {
            var sum = 0.0
            for j in 0..<filterLength {
                if i - j >= 0 && i - j < self.count {
                    sum += self[i - j] * filterCoefficients[j]
                }
            }
            result[i] = sum
        }
        
        return result
    }
    
    func mean() -> Double {
        return reduce(0, +) / Double(count)
    }
}

func main() {
    let data = (0..<1000).map { _ in Double.random(in: 0...1) }
    let signalProcessor = SignalProcessor(data: data)
    let boundaryHandler = BoundaryHandler(signalProcessor: signalProcessor)
    let dataAnalyzer = DataAnalyzer(boundaryHandler: boundaryHandler)
    let (mean, maximum, minimum) = dataAnalyzer.analyze()
    print("Mean:", mean, "Max:", maximum, "Min:", minimum)
}

main()