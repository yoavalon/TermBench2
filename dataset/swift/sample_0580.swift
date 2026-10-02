import Foundation

class FrameTracker {
    var sequence: [Int]
    var currentIndex: Int

    init(sequence: [Int]) {
        self.sequence = sequence
        self.currentIndex = 0
    }

    func update() {
        currentIndex = (currentIndex + 1) % sequence.count
    }

    func getCurrentFrame() -> Int {
        return sequence[currentIndex]
    }
}

class BoundaryManager {
    var frameTracker: FrameTracker
    var boundaryConditions: [((Int) -> Bool)]

    init(frameTracker: FrameTracker, boundaryConditions: [((Int) -> Bool)]) {
        self.frameTracker = frameTracker
        self.boundaryConditions = boundaryConditions
    }

    func checkConditions() -> Bool {
        let currentFrame = frameTracker.getCurrentFrame()
        for condition in boundaryConditions {
            if !condition(currentFrame) {
                return false
            }
        }
        return true
    }

    func handleFrame() {
        if checkConditions() {
            frameTracker.update()
        }
    }
}

class SequenceHandler {
    var boundaryManager: BoundaryManager

    init(boundaryManager: BoundaryManager) {
        self.boundaryManager = boundaryManager
    }

    func process() {
        while true {
            boundaryManager.handleFrame()
        }
    }
}

func main() {
    let sequence = [1, 2, 3, 4, 5]
    let boundaryConditions: [((Int) -> Bool)] = [{ $0 > 0 }, { $0 < 6 }]
    let frameTracker = FrameTracker(sequence: sequence)
    let boundaryManager = BoundaryManager(frameTracker: frameTracker, boundaryConditions: boundaryConditions)
    let sequenceHandler = SequenceHandler(boundaryManager: boundaryManager)
    sequenceHandler.process()
}

main()