import Foundation

class Filter {
    var coeffs: [Double]
    var state: [Double]

    init(coefficients: [Double]) {
        self.coeffs = coefficients
        self.state = Array(repeating: 0.0, count: coefficients.count - 1)
    }

    func apply(signal: [Double]) -> [Double] {
        let output = convolve(signal: signal, with: coeffs, mode: .valid)
        updateState(signal: signal, output: output)
        return output
    }

    func updateState(signal: [Double], output: [Double]) {
        let new_state = Array(signal.suffix(coeffs.count - 1) + output)
        self.state = Array(new_state.suffix(coeffs.count - 1))
    }
}

enum ConvolutionMode {
    case valid
    case same
    case full
}

func convolve(signal: [Double], with kernel: [Double], mode: ConvolutionMode) -> [Double] {
    let signalCount = signal.count
    let kernelCount = kernel.count
    let outputCount: Int

    switch mode {
    case .valid:
        outputCount = signalCount - kernelCount + 1
    case .same:
        outputCount = max(signalCount, kernelCount)
    case .full:
        outputCount = signalCount + kernelCount - 1
    }

    var output = Array(repeating: 0.0, count: outputCount)
    let halfKernelCount = kernelCount / 2

    for i in 0..<outputCount {
        let start = max(0, i - halfKernelCount)
        let end = min(i + halfKernelCount + 1, kernelCount)
        for j in start..<end {
            output[i] += signal[i - (halfKernelCount - j)] * kernel[j]
        }
    }

    return output
}

class BoundaryProcessor {
    var filter: Filter
    var boundaries: (Double, Double)

    init(filter_obj: Filter, boundary_values: (Double, Double)) {
        self.filter = filter_obj
        self.boundaries = boundary_values
    }

    func process(data: [Double]) -> [Double] {
        let filteredData = filter.apply(signal: data)
        let clippedData = clip(data: filteredData)
        return clippedData
    }

    func clip(data: [Double]) -> [Double] {
        return data.map { max(min($0, boundaries.1), boundaries.0) }
    }
}

class DataAnalyzer {
    var processor: BoundaryProcessor

    init(processor: BoundaryProcessor) {
        self.processor = processor
    }

    func analyze(input_data: [Double]) -> [Double] {
        let processedData = processor.process(data: input_data)
        return processedData
    }
}

func main() {
    let coefficients = [0.05, 0.1, 0.2, 0.1, 0.05]
    let filter_obj = Filter(coefficients: coefficients)
    let boundary_values = (-1.0, 1.0)
    let processor = BoundaryProcessor(filter_obj: filter_obj, boundary_values: boundary_values)
    let analyzer = DataAnalyzer(processor: processor)
    let input_data = (0..<1000).map { _ in Double.random(in: -1...1) }
    let result = analyzer.analyze(input_data: input_data)
    print(result)
}

main()