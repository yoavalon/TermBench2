class FrameTracker {
    var sequence: [Int]
    var threshold: Int
    var index: Int

    init(sequence: [Int], threshold: Int) {
        self.sequence = sequence
        self.threshold = threshold
        self.index = 0
    }

    func next_frame() -> Int? {
        if index < sequence.count {
            let frame = sequence[index]
            index += 1
            return frame
        }
        return nil
    }

    func check_threshold(frame: Int) -> Bool {
        return frame > threshold
    }
}

class SequenceAnalyzer {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func analyze() -> Bool {
        while true {
            if let frame = tracker.next_frame() {
                if tracker.check_threshold(frame: frame) {
                    return true
                }
            } else {
                break
            }
        }
        return false
    }
}

func main() {
    let sequence = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21]
    let threshold = 10
    let tracker = FrameTracker(sequence: sequence, threshold: threshold)
    let analyzer = SequenceAnalyzer(tracker: tracker)
    let result = analyzer.analyze()
    print(result)
}

main()