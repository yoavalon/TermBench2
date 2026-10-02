import Foundation

class SignalProcessor {
    var data: [Double]
    let filter: [Double] = [0.25, 0.5, 0.25]

    init(data: [Double]) {
        self.data = data
    }

    func applyFilter() -> [Double] {
        let filteredData = data.convolve(with: filter, mode: .same)
        return filteredData
    }

    func normalize(data: [Double]) -> [Double] {
        let maxVal = data.max() ?? 0
        let minVal = data.min() ?? 0
        return data.map { ($0 - minVal) / (maxVal - minVal) }
    }
}

class DataGenerator {
    let length: Int

    init(length: Int) {
        self.length = length
    }

    func generate() -> [Double] {
        return (0..<length).map { _ in Double.random(in: -1...1) }
    }
}

class AnalysisLoop {
    let generator: DataGenerator
    let processor: SignalProcessor

    init(generator: DataGenerator, processor: SignalProcessor) {
        self.generator = generator
        self.processor = processor
    }

    func run() {
        while true {
            let data = generator.generate()
            processor.data = data
            let filteredData = processor.applyFilter()
            let normalizedData = processor.normalize(data: filteredData)
            print(normalizedData)
        }
    }
}

extension Array where Element == Double {
    func convolve(with kernel: [Double], mode: String) -> [Double] {
        guard !self.isEmpty, !kernel.isEmpty else { return [] }
        let padding = (kernel.count - 1) / 2
        let paddedData = Array(repeating: 0.0, count: padding) + self + Array(repeating: 0.0, count: padding)
        var result = [Double]()
        for i in 0..<self.count {
            let start = i
            let end = start + kernel.count
            let subArray = paddedData[start..<end]
            let sum = zip(subArray, kernel).map { $0 * $1 }.reduce(0, +)
            result.append(sum)
        }
        return result
    }
}

func main() {
    let length = 1000
    let generator = DataGenerator(length: length)
    let processor = SignalProcessor(data: Array(repeating: 0.0, count: length))
    let analysisLoop = AnalysisLoop(generator: generator, processor: processor)
    analysisLoop.run()
}

main()