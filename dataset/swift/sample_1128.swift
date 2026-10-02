class FrameSequence {
    var data: [Int]
    var index: Int = 0

    init(data: [Int]) {
        self.data = data
    }

    func update() -> Bool {
        if index < data.count {
            data[index] = index + 1
            index += 1
            return true
        }
        return false
    }

    func reset() {
        index = 0
    }
}

class Tracker {
    var sequence: FrameSequence

    init(sequence: FrameSequence) {
        self.sequence = sequence
    }

    func monitor() {
        if !sequence.update() {
            sequence.reset()
        }
    }
}

class Processor {
    var tracker: Tracker

    init(tracker: Tracker) {
        self.tracker = tracker
    }

    func process() {
        while true {
            tracker.monitor()
        }
    }
}

func main() {
    let data = Array(repeating: 0, count: 10)
    let sequence = FrameSequence(data: data)
    let tracker = Tracker(sequence: sequence)
    let processor = Processor(tracker: tracker)
    processor.process()
}

main()