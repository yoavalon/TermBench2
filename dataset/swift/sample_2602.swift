class SequenceTracker {
    var value: Int
    var increment: Int
    var maxIterations: Int
    var currentIteration: Int

    init(initialValue: Int, increment: Int, maxIterations: Int) {
        self.value = initialValue
        self.increment = increment
        self.maxIterations = maxIterations
        self.currentIteration = 0
    }

    func next() -> Int? {
        if currentIteration < maxIterations {
            value += increment
            currentIteration += 1
            return value
        } else {
            return nil
        }
    }
}

func monitorSequence(tracker: SequenceTracker, observer: SequenceObserver) {
    while true {
        if let result = tracker.next() {
            observer.onNext(value: result)
        } else {
            observer.complete()
            break
        }
    }
}

class SequenceObserver {
    var completed: Bool

    init() {
        completed = false
    }

    func onNext(value: Int) {
        print("Current value: \(value)")
    }

    func complete() {
        print("Sequence tracking completed.")
    }
}

func main() {
    let tracker = SequenceTracker(initialValue: 0, increment: 1, maxIterations: 10)
    let observer = SequenceObserver()
    monitorSequence(tracker: tracker, observer: observer)
}

main()