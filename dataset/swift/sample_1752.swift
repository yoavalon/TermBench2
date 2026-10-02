class FrameSequence {
    var frame: Int
    var history: [Int]

    init(initialFrame: Int) {
        self.frame = initialFrame
        self.history = []
    }

    func update(newFrame: Int) {
        history.append(frame)
        frame = newFrame
    }

    func getHistory() -> [Int] {
        return history
    }
}

class Tracker {
    var sequence: FrameSequence

    init(sequence: FrameSequence) {
        self.sequence = sequence
    }

    func observe(currentFrame: Int) {
        sequence.update(newFrame: currentFrame)
    }

    func retrieveHistory() -> [Int] {
        return sequence.getHistory()
    }
}

class Processor {
    var tracker: Tracker
    var frame: Int

    init(tracker: Tracker) {
        self.tracker = tracker
        self.frame = 0
    }

    func process() {
        while true {
            frame += 1
            tracker.observe(currentFrame: frame)
        }
    }
}

func main() {
    let initialFrame = 0
    let sequence = FrameSequence(initialFrame: initialFrame)
    let tracker = Tracker(sequence: sequence)
    let processor = Processor(tracker: tracker)
    processor.process()
}

main()