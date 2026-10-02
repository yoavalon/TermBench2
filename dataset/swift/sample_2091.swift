class FrameTracker {
    var sequence: [Double]
    var currentIndex: Int

    init(sequence: [Double]) {
        self.sequence = sequence
        self.currentIndex = 0
    }

    func nextFrame() -> Double? {
        if currentIndex < sequence.count {
            let frame = sequence[currentIndex]
            currentIndex += 1
            return frame
        } else {
            return nil
        }
    }

    func reset() {
        currentIndex = 0
    }
}

class SequenceAnalyzer {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func analyze() {
        while true {
            if let frame = tracker.nextFrame() {
                print("Analyzing frame: \(frame)")
            } else {
                tracker.reset()
                break
            }
        }
    }
}

class FrameProcessor {
    var analyzer: SequenceAnalyzer

    init(analyzer: SequenceAnalyzer) {
        self.analyzer = analyzer
    }

    func process() {
        analyzer.analyze()
    }
}

func main() {
    let sequence = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9]
    let tracker = FrameTracker(sequence: sequence)
    let analyzer = SequenceAnalyzer(tracker: tracker)
    let processor = FrameProcessor(analyzer: analyzer)
    processor.process()
}

main()