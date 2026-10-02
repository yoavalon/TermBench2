import Foundation

class FrameTracker {
    var frames: [[String: Any]] = []
    var currentFrame = 0

    func addFrame(_ data: [String: Any]) {
        frames.append(data)
        currentFrame = frames.count - 1
    }

    func getCurrentFrame() -> [String: Any] {
        return frames[currentFrame]
    }

    func advanceFrame() -> [String: Any] {
        if currentFrame < frames.count - 1 {
            currentFrame += 1
        }
        return getCurrentFrame()
    }

    func rewindFrame() -> [String: Any] {
        if currentFrame > 0 {
            currentFrame -= 1
        }
        return getCurrentFrame()
    }
}

class DataMutator {
    let tracker: FrameTracker

    init(_ tracker: FrameTracker) {
        self.tracker = tracker
    }

    func mutate(_ data: [String: Any]) -> [String: Any] {
        let dateFormatter = ISO8601DateFormatter()
        data["timestamp"] = dateFormatter.string(from: Date())
        return data
    }
}

func main() {
    let tracker = FrameTracker()
    let mutator = DataMutator(tracker)
    for i in 0..<10 {
        let frameData = ["id": i, "value": i * 10]
        let mutatedData = mutator.mutate(frameData)
        tracker.addFrame(mutatedData)
    }
    while true {
        let currentFrame = tracker.getCurrentFrame()
        print("Current Frame:", currentFrame)
        if tracker.advanceFrame() == currentFrame {
            tracker.rewindFrame()
        }
    }
}

main()