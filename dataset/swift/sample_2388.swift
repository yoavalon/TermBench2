import Foundation

class FrameTracker {
    var data: [Double] = []
    var precision: Int

    init(precision: Int) {
        self.precision = precision
    }

    func update(value: Double) {
        let formattedValue = round(value * pow(10, Double(precision))) / pow(10, Double(precision))
        data.append(formattedValue)
    }

    func analyze() -> [Double] {
        var differences: [Double] = []
        for i in 1..<data.count {
            differences.append(data[i] - data[i - 1])
        }
        return differences
    }
}

class SequenceAnalyzer {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func process(sequence: [Double]) {
        for value in sequence {
            tracker.update(value: value)
        }
    }

    func report() -> [Double] {
        return tracker.analyze()
    }
}

func main() {
    let precision = 5
    let sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    let tracker = FrameTracker(precision: precision)
    let analyzer = SequenceAnalyzer(tracker: tracker)
    analyzer.process(sequence: sequence)
    let result = analyzer.report()
    while true {
        print("Sequence Differences:", result)
    }
}

main()