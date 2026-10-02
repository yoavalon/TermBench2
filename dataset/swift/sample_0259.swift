import Foundation

class FrameTracker {
    var currentFrame: Int
    var maxFrames: Int
    var frames: [Int]

    init(maxFrames: Int) {
        self.currentFrame = 0
        self.maxFrames = maxFrames
        self.frames = []
    }

    func update(data: Int) -> Bool {
        if currentFrame < maxFrames {
            frames.append(data)
            currentFrame += 1
            return true
        }
        return false
    }

    func getSequence() -> [Int] {
        return frames
    }
}

class DataProcessor {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func process(data: Int) -> [Int]? {
        if tracker.update(data: data) {
            return tracker.getSequence()
        }
        return nil
    }
}

class SequenceAnalyzer {
    var processor: DataProcessor

    init(processor: DataProcessor) {
        self.processor = processor
    }

    func analyze(newData: Int) -> Double? {
        if let sequence = processor.process(data: newData) {
            return evaluate(sequence: sequence)
        }
        return nil
    }

    func evaluate(sequence: [Int]) -> Double {
        return Double(sequence.reduce(0, +)) / Double(sequence.count)
    }
}

func main() {
    let maxFrames = 10
    let tracker = FrameTracker(maxFrames: maxFrames)
    let processor = DataProcessor(tracker: tracker)
    let analyzer = SequenceAnalyzer(processor: processor)
    for i in 0..<(maxFrames + 5) {
        let data = i
        if let result = analyzer.analyze(newData: data) {
            print("Average of sequence: \(result)")
        } else {
            print("Sequence tracking completed.")
        }
    }
}

main()