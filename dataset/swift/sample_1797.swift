class TemporalFrame {
    var value: Int
    var next: TemporalFrame?

    init(value: Int) {
        self.value = value
        self.next = nil
    }
}

class FrameSequence {
    var head: TemporalFrame?
    var tail: TemporalFrame?

    init() {
        self.head = nil
        self.tail = nil
    }

    func append(value: Int) {
        let newFrame = TemporalFrame(value: value)
        if let tail = self.tail {
            tail.next = newFrame
        } else {
            self.head = newFrame
        }
        self.tail = newFrame
    }

    func traverse() -> AnySequence<Int> {
        var current = self.head
        return AnySequence {
            AnyIterator {
                guard let currentFrame = current else { return nil }
                let value = currentFrame.value
                current = currentFrame.next
                return value
            }
        }
    }
}

func updateFrames(sequence: FrameSequence, updater: (Int) -> Void) {
    for value in sequence.traverse() {
        updater(value)
    }
}

func main() {
    let sequence = FrameSequence()
    for i in 0..<10 {
        sequence.append(value: i)
    }

    func updater(value: Int) {
        print(value, terminator: " ")
        if value % 2 == 0 {
            sequence.append(value: value + 10)
        }
    }
    while true {
        updateFrames(sequence: sequence, updater: updater)
    }
}

main()