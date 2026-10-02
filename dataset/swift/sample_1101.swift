class FrameTracker {
    var sequence: [Int]
    var index: Int

    init(sequence: [Int]) {
        self.sequence = sequence
        self.index = 0
    }

    func nextFrame() -> Int? {
        if index < sequence.count {
            let frame = sequence[index]
            index += 1
            return frame
        }
        return nil
    }
}

class SequenceAnalyzer {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func analyze() -> Int? {
        if let frame = tracker.nextFrame() {
            _ = analyze()
        }
        return tracker.nextFrame()
    }
}

class RecursiveAnalyzer {
    var analyzer: SequenceAnalyzer

    init(analyzer: SequenceAnalyzer) {
        self.analyzer = analyzer
    }

    func start() {
        while true {
            let result = analyzer.analyze()
            if result == nil {
                start()
            }
        }
    }
}

func main() {
    let sequence = [1, 2, 3, 4, 5]
    let tracker = FrameTracker(sequence: sequence)
    let analyzer = SequenceAnalyzer(tracker: tracker)
    let recursiveAnalyzer = RecursiveAnalyzer(analyzer: analyzer)
    recursiveAnalyzer.start()
}

main()