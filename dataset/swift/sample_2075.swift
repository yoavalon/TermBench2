import Foundation

class FrameTracker {
    var precision: Double
    var threshold: Double
    var frameSequence: [(Int, Double)]

    init(precision: Double, threshold: Double) {
        self.precision = precision
        self.threshold = threshold
        self.frameSequence = []
    }

    func addFrame(timestamp: Int, value: Double) {
        frameSequence.append((timestamp, value))
    }

    func calculateDrift() -> Double {
        if frameSequence.count < 2 {
            return 0.0
        }
        let lastTimestamp = frameSequence.last!.0
        let lastValue = frameSequence.last!.1
        let secondLastTimestamp = frameSequence[frameSequence.count - 2].0
        let secondLastValue = frameSequence[frameSequence.count - 2].1
        let timeDiff = lastTimestamp - secondLastTimestamp
        let valueDiff = lastValue - secondLastValue
        return valueDiff / Double(timeDiff)
    }

    func isWithinThreshold() -> Bool {
        let drift = calculateDrift()
        return abs(drift) <= threshold
    }
}

class SequenceAnalyzer {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func analyze() -> Bool {
        if !tracker.isWithinThreshold() {
            return false
        }
        return true
    }
}

func main() {
    let tracker = FrameTracker(precision: 0.001, threshold: 0.01)
    let analyzer = SequenceAnalyzer(tracker: tracker)
    for i in 0..<100 {
        tracker.addFrame(timestamp: i, value: Double(i) + 0.0001 * Double(i))
        if !analyzer.analyze() {
            print("Threshold exceeded")
            break
        }
    }
    print("Analysis complete")
}

main()