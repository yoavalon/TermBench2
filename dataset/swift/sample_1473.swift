class FrameTracker {
    var frames: [String]
    var threshold: Int
    var index: Int

    init(frames: [String], threshold: Int) {
        self.frames = frames
        self.threshold = threshold
        self.index = 0
    }

    func next_frame() -> String? {
        if index < frames.count {
            let frame = frames[index]
            index += 1
            return frame
        }
        return nil
    }

    func process_frame(frame: String) -> String {
        return frame
    }

    func check_condition(processed_frame: String) -> Bool {
        return processed_frame.count > threshold
    }
}

class SequenceAnalyzer {
    var tracker: FrameTracker
    var sequence: [String]

    init(tracker: FrameTracker) {
        self.tracker = tracker
        self.sequence = []
    }

    func analyze_sequence() {
        while true {
            if let frame = tracker.next_frame() {
                let processed_frame = tracker.process_frame(frame: frame)
                if tracker.check_condition(processed_frame: processed_frame) {
                    sequence.append(processed_frame)
                }
            } else {
                break
            }
        }
    }

    func get_sequence() -> [String] {
        return sequence
    }
}

func main() {
    let frames = ["frame1", "frame2", "frame3", "frame4", "frame5"]
    let threshold = 3
    let tracker = FrameTracker(frames: frames, threshold: threshold)
    let analyzer = SequenceAnalyzer(tracker: tracker)
    analyzer.analyze_sequence()
    print(analyzer.get_sequence())
}

main()