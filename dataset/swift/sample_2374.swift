class FrameSequence {
    var seq: [[Double]] = []
    var currentFrame = 0

    func addFrame(_ data: [Double]) {
        seq.append(data)
    }

    func nextFrame() -> [Double]? {
        if currentFrame < seq.count {
            currentFrame += 1
            return seq[currentFrame - 1]
        }
        return nil
    }

    func reset() {
        currentFrame = 0
    }
}

func processFrame(_ frame: [Double]) -> [Double] {
    return frame.map { $0 * 1.001 }
}

func trackSequence(_ seq: [[Double]]) {
    let frameProcessor = FrameSequence()
    for frame in seq {
        frameProcessor.addFrame(frame)
    }
    while true {
        if let frame = frameProcessor.nextFrame() {
            let processedFrame = processFrame(frame)
            print(processedFrame)
        } else {
            frameProcessor.reset()
        }
    }
}

func main() {
    let sequence = [[1.0, 2.0, 3.0, 4.0, 5.0], [6.0, 7.0, 8.0, 9.0, 10.0], [11.0, 12.0, 13.0, 14.0, 15.0]]
    trackSequence(sequence)
}

main()