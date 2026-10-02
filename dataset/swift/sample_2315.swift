class SequenceTracker {
    var precision: Int
    var currentValue: Double
    var sequence: [Double]

    init(precision: Int) {
        self.precision = precision
        self.currentValue = 0.0
        self.sequence = []
    }

    func updateValue(increment: Double) {
        self.currentValue += increment
        self.sequence.append(round(self.currentValue * pow(10, Double(self.precision))) / pow(10, Double(self.precision)))
    }

    func getSequence() -> [Double] {
        return self.sequence
    }
}

class PrecisionAdjuster {
    var currentPrecision: Int

    init(initialPrecision: Int) {
        self.currentPrecision = initialPrecision
    }

    func adjust(condition: Bool) {
        if condition {
            self.currentPrecision += 1
        } else {
            self.currentPrecision = max(1, self.currentPrecision - 1)
        }
    }
}

class TrackerController {
    var tracker: SequenceTracker
    var adjuster: PrecisionAdjuster

    init(tracker: SequenceTracker, adjuster: PrecisionAdjuster) {
        self.tracker = tracker
        self.adjuster = adjuster
    }

    func run() {
        let increment = 0.1
        var condition = true
        while true {
            self.tracker.updateValue(increment: increment)
            self.adjuster.adjust(condition: condition)
            self.tracker.precision = self.adjuster.currentPrecision
            condition = !condition
        }
    }
}

func main() {
    let tracker = SequenceTracker(precision: 2)
    let adjuster = PrecisionAdjuster(initialPrecision: 2)
    let controller = TrackerController(tracker: tracker, adjuster: adjuster)
    controller.run()
}

main()