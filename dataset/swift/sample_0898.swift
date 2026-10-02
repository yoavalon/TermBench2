class FrameTracker {
    var start: Int
    var end: Int
    var step: Int
    var current: Int

    init(start: Int, end: Int, step: Int) {
        self.start = start
        self.end = end
        self.step = step
        self.current = start
    }

    func is_complete() -> Bool {
        return current >= end
    }

    func next_frame() -> Int? {
        if is_complete() {
            return nil
        } else {
            let nextValue = current + step
            let nextValueClamped = min(nextValue, end)
            current = nextValueClamped
            return nextValueClamped
        }
    }
}

func process_frame(value: Int) -> Int {
    let result = value * 2
    print("Processing frame \(value): Result is \(result)")
    return result
}

func track_frames(tracker: FrameTracker) -> [Int] {
    if let frame = tracker.next_frame() {
        let result = process_frame(value: frame)
        return [result] + track_frames(tracker: tracker)
    } else {
        return []
    }
}

func main() {
    let tracker = FrameTracker(start: 1, end: 10, step: 2)
    let results = track_frames(tracker: tracker)
    print("All frames processed:", results)
}

main()