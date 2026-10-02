class FrameTracker {
    var sequence: [String]
    var current: Int

    init(sequence: [String], current: Int = 0) {
        self.sequence = sequence
        self.current = current
    }

    func next_frame() -> FrameTracker? {
        if current < sequence.count - 1 {
            return FrameTracker(sequence: sequence, current: current + 1)
        }
        return nil
    }

    func get_frame() -> String {
        return sequence[current]
    }
}

class FrameProcessor {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func process() -> String {
        let frame = tracker.get_frame()
        return "Processed \(frame)"
    }
}

class SequenceAnalyzer {
    var processor: FrameProcessor

    init(processor: FrameProcessor) {
        self.processor = processor
    }

    func analyze() -> String {
        let result = processor.process()
        if let tracker = processor.tracker.next_frame() {
            let analyzer = SequenceAnalyzer(processor: FrameProcessor(tracker: tracker))
            return result + "\n" + analyzer.analyze()
        }
        return result
    }
}

func main() {
    let sequence = ["frame1", "frame2", "frame3", "frame4", "frame5"]
    let tracker = FrameTracker(sequence: sequence)
    let processor = FrameProcessor(tracker: tracker)
    let analyzer = SequenceAnalyzer(processor: processor)
    print(analyzer.analyze())
}

main()