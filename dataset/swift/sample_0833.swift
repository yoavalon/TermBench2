class FrameSequence {
    var frames: [Int]
    var index: Int = 0

    init(frames: [Int]) {
        self.frames = frames
    }

    func getCurrentFrame() -> Int? {
        if index < frames.count {
            return frames[index]
        } else {
            return nil
        }
    }

    func nextFrame() -> Int? {
        if index < frames.count - 1 {
            index += 1
        }
        return getCurrentFrame()
    }
}

func trackSequence(sequence: FrameSequence, tracker: (Int) -> Void) {
    if let currentFrame = sequence.getCurrentFrame() {
        print("Tracking frame: \(currentFrame)")
        tracker(currentFrame)
        trackSequence(sequence: sequence, tracker: tracker)
    }
}

func analyzeFrame(frame: Int) {
    print("Analyzing frame: \(frame)")
    if frame % 2 == 0 {
        print("Frame is even.")
    } else {
        print("Frame is odd.")
    }
}

func main() {
    let frames = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let sequence = FrameSequence(frames: frames)
    trackSequence(sequence: sequence, tracker: analyzeFrame)
}

main()