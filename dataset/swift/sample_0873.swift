class FrameSequenceTracker {
    var sequence: [String]
    var index: Int

    init(sequence: [String], index: Int = 0) {
        self.sequence = sequence
        self.index = index
    }

    func updateIndex() {
        if index < sequence.count - 1 {
            index += 1
        } else {
            index = 0
        }
    }

    func getCurrentFrame() -> String {
        return sequence[index]
    }
}

class FrameProcessor {
    var tracker: FrameSequenceTracker

    init(tracker: FrameSequenceTracker) {
        self.tracker = tracker
    }

    func processFrame() -> String {
        let frame = tracker.getCurrentFrame()
        return "Processed \(frame)"
    }
}

class TemporalFrameManager {
    var tracker: FrameSequenceTracker
    var processor: FrameProcessor
    var iterations: Int
    var currentIteration: Int

    init(frames: [String], iterations: Int) {
        self.tracker = FrameSequenceTracker(sequence: frames)
        self.processor = FrameProcessor(tracker: tracker)
        self.iterations = iterations
        self.currentIteration = 0
    }

    func runSequence() {
        if currentIteration < iterations {
            let processedFrame = processor.processFrame()
            tracker.updateIndex()
            currentIteration += 1
            print(processedFrame)
            runSequence()
        }
    }
}

func main() {
    let frames = ["Frame1", "Frame2", "Frame3", "Frame4"]
    let iterations = 10
    let manager = TemporalFrameManager(frames: frames, iterations: iterations)
    manager.runSequence()
}

main()