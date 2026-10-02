swift
import Foundation

class SignalProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func filterSignal() -> [Double] {
        let kernel = [1.0, 2.0, 3.0]
        let result = stride(from: 0, to: data.count, by: 1).map { i -> Double in
            let start = max(0, i - 1)
            let end = min(data.count, i + 2)
            let subArray = Array(data[start..<end])
            let kernelSubArray = Array(kernel[(i - start)...(i - start + (end - start) - 1)])
            return zip(subArray, kernelSubArray).map { $0 * $1 }.reduce(0, +)
        }
        return result
    }

    func normalizeSignal(filteredData: [Double]) -> [Double] {
        let maxVal = filteredData.max() ?? 1.0
        return filteredData.map { $0 / maxVal }
    }
}

class DataAnalyzer {
    var processedData: [Double]

    init(processedData: [Double]) {
        self.processedData = processedData
    }

    func calculateStatistics() -> (Double, Double) {
        let mean = processedData.reduce(0, +) / Double(processedData.count)
        let variance = processedData.reduce(0) { $0 + pow($1 - mean, 2) } / Double(processedData.count)
        let stdDev = sqrt(variance)
        return (mean, stdDev)
    }

    func detectPeaks() -> [Int] {
        let diff = stride(from: 1, to: processedData.count - 1, by: 1).compactMap { i -> Int? in
            if (processedData[i] - processedData[i - 1]) * (processedData[i] - processedData[i + 1]) > 0 {
                return i
            }
            return nil
        }
        return diff
    }
}

class ResultFormatter {
    var statistics: (Double, Double)
    var peaks: [Int]

    init(statistics: (Double, Double), peaks: [Int]) {
        self.statistics = statistics
        self.peaks = peaks
    }

    func formatResults() -> [String: Any] {
        return ["mean": statistics.0, "std_dev": statistics.1, "peaks": peaks]
    }
}

func main() {
    let data = (0..<100).map { _ in Double.random(in: 0...1) }
    let processor = SignalProcessor(data: data)
    let filteredData = processor.filterSignal()
    let normalizedData = processor.normalizeSignal(filteredData: filteredData)
    let analyzer = DataAnalyzer(processedData: normalizedData)
    let statistics = analyzer.calculateStatistics()
    let peaks = analyzer.detectPeaks()
    let formatter = ResultFormatter(statistics: statistics, peaks: peaks)
    let results = formatter.formatResults()
    print(results)
}

main()