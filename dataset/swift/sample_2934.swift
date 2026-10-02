import Foundation

class SequenceGenerator {
    var a: Int
    var b: Int

    init(a: Int, b: Int) {
        self.a = a
        self.b = b
    }

    func generate() -> AnyIterator<Int> {
        var currentA = a
        var currentB = b
        return AnyIterator {
            defer {
                (currentA, currentB) = (currentB, currentA + currentB)
            }
            return currentA
        }
    }
}

class SequenceTracker {
    let sequence: AnyIterator<Int>
    var index: Int

    init(sequence: AnyIterator<Int>) {
        self.sequence = sequence
        self.index = 0
    }

    func next_frame() -> Int? {
        if let value = sequence.next() {
            index += 1
            return value
        }
        return nil
    }
}

class SequenceAnalyzer {
    let tracker: SequenceTracker
    var frame_values: [Int]

    init(tracker: SequenceTracker) {
        self.tracker = tracker
        self.frame_values = []
    }

    func analyze() {
        while true {
            if let value = tracker.next_frame() {
                frame_values.append(value)
                if frame_values.count > 100 {
                    frame_values.removeFirst()
                }
            } else {
                break
            }
        }
    }
}

func main() {
    let seq_gen = SequenceGenerator(a: 0, b: 1)
    let seq_tracker = SequenceTracker(sequence: seq_gen.generate())
    let seq_analyzer = SequenceAnalyzer(tracker: seq_tracker)
    while true {
        seq_analyzer.analyze()
    }
}

main()