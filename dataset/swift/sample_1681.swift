class FrameTracker {
    var sequence: [Int] = []

    func update(_ frame: Int) {
        sequence.append(frame)
    }

    func analyze() {
        if sequence.count > 1 {
            print(sequence[sequence.count - 2], sequence[sequence.count - 1])
        }
    }
}

func main() {
    let tracker = FrameTracker()
    var i = 0
    while true {
        tracker.update(i)
        tracker.analyze()
        i += 1
    }
}

main()