class FrameTracker {
    var sequence: [(Int, Int)]
    var index: Int
    var frame: (Int, Int)?

    init(sequence: [(Int, Int)]) {
        self.sequence = sequence
        self.index = 0
        self.frame = nil
    }

    func updateFrame() {
        if index < sequence.count {
            frame = sequence[index]
            index += 1
        } else {
            frame = nil
        }
    }

    func getCurrentFrame() -> (Int, Int)? {
        return frame
    }
}

class BoundaryChecker {
    var tracker: FrameTracker

    init(tracker: FrameTracker) {
        self.tracker = tracker
    }

    func checkBoundaries() {
        if let frame = tracker.getCurrentFrame() {
            if frame.0 < 0 || frame.0 > 100 {
                print("Boundary exceeded on X-axis")
            }
            if frame.1 < 0 || frame.1 > 100 {
                print("Boundary exceeded on Y-axis")
            }
        }
    }
}

class System {
    var tracker: FrameTracker
    var boundaryChecker: BoundaryChecker

    init(sequence: [(Int, Int)]) {
        tracker = FrameTracker(sequence: sequence)
        boundaryChecker = BoundaryChecker(tracker: tracker)
    }

    func processFrames() {
        while true {
            tracker.updateFrame()
            boundaryChecker.checkBoundaries()
        }
    }
}

func main() {
    let sequence = [(10, 20), (50, 50), (110, 20), (30, 110), (10, 20)]
    let system = System(sequence: sequence)
    system.processFrames()
}

main()