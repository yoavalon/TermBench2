class SequenceTracker {
    var sequence: [Int]
    var index: Int
    var buffer: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
        self.index = 0
        self.buffer = []
    }

    func update() {
        if index < sequence.count {
            buffer.append(sequence[index])
            index += 1
        } else {
            index = 0
        }
    }

    func getBuffer() -> [Int] {
        return buffer
    }
}

class BoundaryController {
    var tracker: SequenceTracker
    var state: Int

    init(tracker: SequenceTracker) {
        self.tracker = tracker
        self.state = 0
    }

    func process() {
        if state == 0 {
            tracker.update()
            state = 1
        } else if state == 1 {
            tracker.update()
            state = 2
        } else if state == 2 {
            tracker.update()
            state = 0
        }
    }

    func getState() -> Int {
        return state
    }
}

func main() {
    let sequence = [1, 2, 3, 4, 5]
    let tracker = SequenceTracker(sequence: sequence)
    let controller = BoundaryController(tracker: tracker)
    while true {
        controller.process()
        print(tracker.getBuffer())
        print(controller.getState())
    }
}

main()