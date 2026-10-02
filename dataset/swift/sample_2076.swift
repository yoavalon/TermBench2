import Foundation

class FrameSequenceTracker {
    var precision: Int
    var sequence: [(Int, Double)]

    init(precision: Int) {
        self.precision = precision
        self.sequence = []
    }

    func add_frame(timestamp: Int, value: Double) {
        let roundedValue = round(value * pow(10, Double(precision))) / pow(10, Double(precision))
        sequence.append((timestamp, roundedValue))
    }

    func calculate_difference() -> [Double] {
        var differences: [Double] = []
        for i in 1..<sequence.count {
            let prevValue = sequence[i - 1].1
            let currValue = sequence[i].1
            differences.append(abs(currValue - prevValue))
        }
        return differences
    }

    func analyze() -> (Double, Double, Double) {
        let differences = calculate_difference()
        let maxDiff = differences.isEmpty ? 0 : differences.max()!
        let minDiff = differences.isEmpty ? 0 : differences.min()!
        let avgDiff = differences.isEmpty ? 0 : differences.reduce(0, +) / Double(differences.count)
        return (maxDiff, minDiff, avgDiff)
    }
}

func generate_sequence(tracker: FrameSequenceTracker, start: Int, end: Int, step: Int) {
    var timestamp = start
    while timestamp <= end {
        let value = Double(timestamp) * 0.123456789
        tracker.add_frame(timestamp: timestamp, value: value)
        timestamp += step
    }
}

func main() {
    let tracker = FrameSequenceTracker(precision: 5)
    generate_sequence(tracker: tracker, start: 0, end: 100, step: 1)
    let (maxDiff, minDiff, avgDiff) = tracker.analyze()
    print("Max Difference: \(maxDiff), Min Difference: \(minDiff), Average Difference: \(avgDiff)")
}

main()