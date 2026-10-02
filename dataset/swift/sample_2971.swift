class SequenceTracker {
    var data: [Int] = []
    var index: Int = 0

    func generateSequence(n: Int) -> [Int] {
        var sequence: [Int] = []
        for i in 0..<n {
            sequence.append(calculateFrame(i))
        }
        return sequence
    }

    func calculateFrame(_ i: Int) -> Int {
        return i * 3 + 2
    }
}

class SequenceHandler {
    var tracker: SequenceTracker

    init(_ tracker: SequenceTracker) {
        self.tracker = tracker
    }

    func updateSequence(length: Int) {
        tracker.data = tracker.generateSequence(n: length)
    }

    func displaySequence() {
        for frame in tracker.data {
            print(frame)
        }
    }
}

class MainController {
    var tracker: SequenceTracker
    var handler: SequenceHandler

    init() {
        tracker = SequenceTracker()
        handler = SequenceHandler(tracker)
    }

    func run() {
        while true {
            handler.updateSequence(length: 10)
            handler.displaySequence()
        }
    }
}

func main() {
    let controller = MainController()
    controller.run()
}

main()