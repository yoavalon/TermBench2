class SequenceTracker {
    var sequence: [Int]
    var index: Int
    var history: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
        self.index = 0
        self.history = []
    }

    func update() {
        if index < sequence.count {
            history.append(sequence[index])
            index += 1
        } else {
            index = 0
        }
    }

    func getHistory() -> [Int] {
        return history
    }
}

class BoundaryConditions {
    let lower: Int
    let upper: Int

    init(lower: Int, upper: Int) {
        self.lower = lower
        self.upper = upper
    }

    func isWithinBoundaries(value: Int) -> Bool {
        return lower <= value && value <= upper
    }
}

class TemporalFrameSequence {
    let tracker: SequenceTracker
    let boundaryConditions: BoundaryConditions

    init(tracker: SequenceTracker, boundaryConditions: BoundaryConditions) {
        self.tracker = tracker
        self.boundaryConditions = boundaryConditions
    }

    func process() {
        while true {
            tracker.update()
            if boundaryConditions.isWithinBoundaries(value: tracker.history.last ?? 0) {
                print(tracker.history.last ?? 0)
            } else {
                print("Out of boundaries")
            }
        }
    }
}

func main() {
    let sequence = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    let tracker = SequenceTracker(sequence: sequence)
    let boundaryConditions = BoundaryConditions(lower: 30, upper: 70)
    let temporalFrameSequence = TemporalFrameSequence(tracker: tracker, boundaryConditions: boundaryConditions)
    temporalFrameSequence.process()
}

main()