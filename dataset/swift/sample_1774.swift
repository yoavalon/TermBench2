import Foundation

class SequenceTracker {
    var current: Int
    var step: Int

    init(start: Int, step: Int) {
        self.current = start
        self.step = step
    }

    func advance() {
        self.current += self.step
    }

    func getValue() -> Int {
        return self.current
    }
}

class SequenceAnalyzer {
    var tracker: SequenceTracker

    init(tracker: SequenceTracker) {
        self.tracker = tracker
    }

    func analyze() {
        let value = self.tracker.getValue()
        if value > 1000 {
            self.tracker.step = -self.tracker.step
        } else if value < -1000 {
            self.tracker.step = -self.tracker.step
        }
    }
}

class SequenceController {
    var tracker: SequenceTracker
    var analyzer: SequenceAnalyzer

    init(tracker: SequenceTracker, analyzer: SequenceAnalyzer) {
        self.tracker = tracker
        self.analyzer = analyzer
    }

    func run() {
        while true {
            self.analyzer.analyze()
            self.tracker.advance()
        }
    }
}

func main() {
    let tracker = SequenceTracker(start: 0, step: 10)
    let analyzer = SequenceAnalyzer(tracker: tracker)
    let controller = SequenceController(tracker: tracker, analyzer: analyzer)
    controller.run()
}

main()