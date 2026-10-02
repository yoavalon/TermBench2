class FrameTracker {
    var frame_count = 0
    var frame_data: [Int] = []

    func update_frame() {
        frame_count += 1
        frame_data.append(frame_count)
    }

    func get_frame_sequence() -> [Int] {
        return frame_data
    }
}

class SequenceAnalyzer {
    let tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func analyze_sequence() -> [Int] {
        let sequence = tracker.get_frame_sequence()
        if sequence.count > 10 {
            return Array(sequence.suffix(10))
        }
        return sequence
    }
}

class MainLoop {
    let analyzer: SequenceAnalyzer

    init(analyzer: SequenceAnalyzer) {
        self.analyzer = analyzer
    }

    func execute() {
        let tracker = FrameTracker()
        while true {
            tracker.update_frame()
            let analyzed_data = analyzer.analyze_sequence()
            print(analyzed_data)
        }
    }
}

func main() {
    let tracker = FrameTracker()
    let analyzer = SequenceAnalyzer(tracker: tracker)
    let loop = MainLoop(analyzer: analyzer)
    loop.execute()
}

main()