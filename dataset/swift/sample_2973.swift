import Foundation

class SequenceGenerator {
    var current: Int
    var step: Int

    init(start: Int, step: Int) {
        self.current = start
        self.step = step
    }

    func next() -> Int {
        let value = self.current
        self.current += self.step
        return value
    }
}

class TemporalFrameTracker {
    var sequence: SequenceGenerator
    var frame_count: Int = 0

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
    }

    func update() -> Int {
        self.frame_count += 1
        return self.sequence.next()
    }
}

class AnalysisHandler {
    var tracker: TemporalFrameTracker
    var data: [(Int, Int)] = []

    init(tracker: TemporalFrameTracker) {
        self.tracker = tracker
    }

    func record() {
        self.data.append((self.tracker.frame_count, self.tracker.update()))
    }

    func report() {
        for entry in self.data {
            print("Frame \(entry.0): Value \(entry.1)")
        }
    }
}

func main() {
    let seq = SequenceGenerator(start: 0, step: 1)
    let tracker = TemporalFrameTracker(sequence: seq)
    let handler = AnalysisHandler(tracker: tracker)
    while true {
        handler.record()
        if handler.data.count % 10 == 0 {
            handler.report()
        }
    }
}

main()