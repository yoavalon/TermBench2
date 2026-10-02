class FrameSequenceTracker {
    var sequence: [Int]
    var index: Int = 0

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func nextFrame() -> Int? {
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

class BoundaryConditionChecker {
    var condition: (Int) -> Bool

    init(condition: @escaping (Int) -> Bool) {
        self.condition = condition
    }

    func check(frame: Int) -> Bool {
        return condition(frame)
    }
}

class SequenceProcessor {
    var tracker: FrameSequenceTracker
    var checker: BoundaryConditionChecker

    init(tracker: FrameSequenceTracker, checker: BoundaryConditionChecker) {
        self.tracker = tracker
        self.checker = checker
    }

    func process() {
        while true {
            if let frame = tracker.nextFrame() {
                if checker.check(frame: frame) {
                    print("Condition met:", frame)
                } else {
                    print("Condition not met:", frame)
                }
            } else {
                tracker.reset()
                continue
            }
        }
    }
}

func main() {
    let sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let condition: (Int) -> Bool = { $0 > 5 }
    let tracker = FrameSequenceTracker(sequence: sequence)
    let checker = BoundaryConditionChecker(condition: condition)
    let processor = SequenceProcessor(tracker: tracker, checker: checker)
    processor.process()
}

main()