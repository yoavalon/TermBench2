import Foundation

class SequenceTracker {
    var state: Double = 0.0
    var frameCount: Int = 0

    func update(_ increment: Double) {
        state += increment
        frameCount += 1
    }

    func reset() {
        state = 0.0
        frameCount = 0
    }
}

class FrameProcessor {
    let tracker: SequenceTracker

    init(tracker: SequenceTracker) {
        self.tracker = tracker
    }

    func processFrame(_ data: Double) {
        tracker.update(data)
    }
}

class Controller {
    let processor: FrameProcessor
    let threshold: Double = 1000.0

    init(processor: FrameProcessor) {
        self.processor = processor
    }

    func run() {
        while true {
            let data = generateData()
            processor.processFrame(data)
            if processor.tracker.state > threshold {
                processor.tracker.reset()
            }
        }
    }

    func generateData() -> Double {
        return 0.1
    }
}

func main() {
    let tracker = SequenceTracker()
    let processor = FrameProcessor(tracker: tracker)
    let controller = Controller(processor: processor)
    controller.run()
}

main()