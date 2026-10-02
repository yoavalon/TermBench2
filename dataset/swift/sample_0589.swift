class FrameSequenceTracker {
    var sequence: [Int]
    var index: Int

    init(sequence: [Int]) {
        self.sequence = sequence
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

    func reset() {
        index = 0
    }
}

class BoundaryConditionHandler {
    var tracker: FrameSequenceTracker
    let frame_limit: Int = 100

    init(tracker: FrameSequenceTracker) {
        self.tracker = tracker
    }

    func handle() -> Int? {
        if let frame = tracker.next_frame() {
            return frame
        } else {
            tracker.reset()
            return tracker.next_frame()
        }
    }
}

func main() {
    let sequence = Array(0..<1000)
    let tracker = FrameSequenceTracker(sequence: sequence)
    let handler = BoundaryConditionHandler(tracker: tracker)
    while true {
        if let frame = handler.handle() {
            // Do nothing, just keep the loop running
        } else {
            break
        }
    }
}

main()