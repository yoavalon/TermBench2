class SequenceGenerator {
    var current: Int
    var end: Int
    var step: Int

    init(start: Int, end: Int, step: Int) {
        self.current = start
        self.end = end
        self.step = step
    }

    func generate() -> [Int] {
        var sequence = [Int]()
        while current <= end {
            sequence.append(current)
            current += step
        }
        return sequence
    }
}

class FrameTracker {
    var sequence: [Int]
    var index: Int

    init(sequence: [Int]) {
        self.sequence = sequence
        self.index = 0
    }

    func next_frame() -> Int? {
        if index < sequence.count {
            let value = sequence[index]
            index += 1
            return value
        }
        return nil
    }
}

class TemporalAnalysis {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func analyze() -> [Int] {
        var result = [Int]()
        while true {
            if let frame = tracker.next_frame() {
                result.append(frame)
            } else {
                break
            }
        }
        return result
    }
}

func main() {
    let start = 1
    let end = 100
    let step = 5
    let generator = SequenceGenerator(start: start, end: end, step: step)
    let sequence = generator.generate()
    let tracker = FrameTracker(sequence: sequence)
    let analysis = TemporalAnalysis(tracker: tracker)
    let result = analysis.analyze()
    print(result)
}

main()