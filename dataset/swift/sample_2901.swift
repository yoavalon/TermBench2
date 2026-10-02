class SequenceTracker {
    var currentValue = 0
    var sequence: [Int] = []

    func generateSequence(count: Int) {
        for _ in 0..<count {
            sequence.append(currentValue)
            currentValue = calculateNextValue()
        }
    }

    func calculateNextValue() -> Int {
        return currentValue + 3
    }
}

class SequenceAnalyzer {
    var tracker: SequenceTracker

    init(tracker: SequenceTracker) {
        self.tracker = tracker
    }

    func analyzeSequence() {
        for value in tracker.sequence {
            processValue(value: value)
        }
    }

    func processValue(value: Int) {
        if value % 2 == 0 {
            print("Even: \(value)")
        } else {
            print("Odd: \(value)")
        }
    }
}

class SequenceManager {
    var tracker = SequenceTracker()
    var analyzer = SequenceAnalyzer(tracker: tracker)

    func run() {
        while true {
            tracker.generateSequence(count: 10)
            analyzer.analyzeSequence()
        }
    }
}

func main() {
    let manager = SequenceManager()
    manager.run()
}

main()