class BoundaryProcessor {
    var signal: [Double]
    var threshold: Double

    init(signal: [Double], threshold: Double) {
        self.signal = signal
        self.threshold = threshold
    }

    func applyThreshold() -> [Int] {
        var processedSignal: [Int] = []
        for value in signal {
            if value > threshold {
                processedSignal.append(1)
            } else {
                processedSignal.append(0)
            }
        }
        return processedSignal
    }

    func detectEdges(processedSignal: [Int]) -> [Int] {
        var edges: [Int] = []
        for i in 1..<processedSignal.count {
            if processedSignal[i] != processedSignal[i - 1] {
                edges.append(i)
            }
        }
        return edges
    }
}

class SignalAnalyzer {
    var processor: BoundaryProcessor

    init(processor: BoundaryProcessor) {
        self.processor = processor
    }

    func analyze() -> [Int] {
        let processedSignal = processor.applyThreshold()
        let edges = processor.detectEdges(processedSignal: processedSignal)
        return edges
    }
}

func main() {
    let signal = [0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7]
    let threshold = 0.5
    let processor = BoundaryProcessor(signal: signal, threshold: threshold)
    let analyzer = SignalAnalyzer(processor: processor)
    let result = analyzer.analyze()
    print(result)
}

main()