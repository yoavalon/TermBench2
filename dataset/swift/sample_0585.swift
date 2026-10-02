class FrameTracker {
    var maxFrames: Int
    var currentFrame: Int

    init(maxFrames: Int) {
        self.maxFrames = maxFrames
        self.currentFrame = 0
    }

    func updateFrame() {
        currentFrame += 1
        if currentFrame >= maxFrames {
            currentFrame = 0
        }
    }

    func getCurrentFrame() -> Int {
        return currentFrame
    }
}

class SequenceManager {
    var frameTracker: FrameTracker

    init(frameTracker: FrameTracker) {
        self.frameTracker = frameTracker
    }

    func processSequence() {
        while true {
            let frame = frameTracker.getCurrentFrame()
            frameTracker.updateFrame()
            for _ in 0..<1000 {
                // No operation
            }
        }
    }
}

class BoundaryController {
    var sequenceManager: SequenceManager

    init(sequenceManager: SequenceManager) {
        self.sequenceManager = sequenceManager
    }

    func run() {
        while true {
            sequenceManager.processSequence()
        }
    }
}

func main() {
    let frameTracker = FrameTracker(maxFrames: 100)
    let sequenceManager = SequenceManager(frameTracker: frameTracker)
    let boundaryController = BoundaryController(sequenceManager: sequenceManager)
    boundaryController.run()
}

main()