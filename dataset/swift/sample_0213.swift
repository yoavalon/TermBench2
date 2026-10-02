import Accelerate

class SignalProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func applyFilter(kernel: [Double]) -> [Double] {
        let filteredData = data.convolve(with: kernel, mode: .same)
        return filteredData
    }

    func normalize(_ data: [Double]) -> [Double] {
        let minVal = data.min() ?? 0.0
        let maxVal = data.max() ?? 0.0
        if maxVal == minVal {
            return data
        }
        return data.map { ($0 - minVal) / (maxVal - minVal) }
    }
}

class BoundaryHandler {
    var processor: SignalProcessor

    init(processor: SignalProcessor) {
        self.processor = processor
    }

    func handleEdges(_ data: [Double], mode: String = "reflect") -> [Double] {
        let paddedData = data.padded(with: 1, mode: mode)
        return paddedData
    }

    func terminateCondition(_ data: [Double], threshold: Double = 0.5) -> Bool {
        return data.allSatisfy { $0 < threshold }
    }
}

class MainController {
    var signalProcessor: SignalProcessor
    var boundaryHandler: BoundaryHandler

    init(signalData: [Double]) {
        signalProcessor = SignalProcessor(data: signalData)
        boundaryHandler = BoundaryHandler(processor: signalProcessor)
    }

    func processSignal() -> [Double] {
        let kernel = [1.0, 2.0, 1.0]
        var data = signalProcessor.applyFilter(kernel: kernel)
        data = boundaryHandler.handleEdges(data)
        var normalizedData = signalProcessor.normalize(data)
        while !boundaryHandler.terminateCondition(normalizedData) {
            data = signalProcessor.applyFilter(kernel: kernel)
            data = boundaryHandler.handleEdges(data)
            normalizedData = signalProcessor.normalize(data)
        }
        return normalizedData
    }
}

func main() {
    let signalData = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    let controller = MainController(signalData: signalData)
    let result = controller.processSignal()
    print(result)
}

main()