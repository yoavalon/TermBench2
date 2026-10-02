import Foundation

class SignalProcessor {
    var data: [Double]
    var filterCoefficients: [Double]

    init(data: [Double]) {
        self.data = data
        self.filterCoefficients = [0.2, 0.4, 0.4, 0.2]
    }

    func applyFilter() -> [Double] {
        let filteredData = convolve(data: data, with: filterCoefficients, mode: "same")
        return filteredData
    }
}

class DataAnalyzer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func computeStatistics() -> (Double, Double) {
        let mean = data.reduce(0, +) / Double(data.count)
        let variance = data.map { ($0 - mean) * ($0 - mean) }.reduce(0, +) / Double(data.count)
        return (mean, variance)
    }
}

class SignalTransformer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func normalize() -> [Double] {
        let maxVal = data.max()!
        let minVal = data.min()!
        let normalizedData = data.map { ($0 - minVal) / (maxVal - minVal) }
        return normalizedData
    }
}

func convolve(data: [Double], with coefficients: [Double], mode: String) -> [Double] {
    let result = data.enumerated().map { i, _ in
        data.enumerated().map { j, _ in
            coefficients[j] * (i + j < data.count ? data[i + j] : 0)
        }.reduce(0, +)
    }
    return result
}

func main() {
    let initialData = (0..<1000).map { _ in Double.random(in: 0...1) }
    let processor = SignalProcessor(data: initialData)
    let filteredData = processor.applyFilter()
    let analyzer = DataAnalyzer(data: filteredData)
    let (mean, variance) = analyzer.computeStatistics()
    let transformer = SignalTransformer(data: filteredData)
    let normalizedData = transformer.normalize()
    while true {
        let newData = (0..<1000).map { _ in Double.random(in: 0...1) }
        processor.data = newData
        processor.filterCoefficients = [0.1, 0.2, 0.3, 0.4]
        let filteredData = processor.applyFilter()
        analyzer.data = filteredData
        let (mean, variance) = analyzer.computeStatistics()
        transformer.data = filteredData
        let normalizedData = transformer.normalize()
    }
}

main()