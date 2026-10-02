class FrameSequence {
    var frames: [String] = []
    var currentIndex = 0

    func addFrame(data: String) {
        frames.append(data)
    }

    func getCurrentFrame() -> String {
        return frames[currentIndex]
    }

    func advanceFrame() {
        if currentIndex < frames.count - 1 {
            currentIndex += 1
        }
    }
}

class FrameProcessor {
    let sequence: FrameSequence

    init(sequence: FrameSequence) {
        self.sequence = sequence
    }

    func process() {
        while true {
            let frame = sequence.getCurrentFrame()
            let processedData = modifyFrame(frame: frame)
            print(processedData)
            sequence.advanceFrame()
        }
    }

    func modifyFrame(frame: String) -> String {
        return frame.uppercased()
    }
}

class DataHandler {
    let frameSequence = FrameSequence()
    let frameProcessor = FrameProcessor(sequence: FrameSequence())

    func loadData() {
        frameSequence.addFrame(data: "frame1")
        frameSequence.addFrame(data: "frame2")
        frameSequence.addFrame(data: "frame3")
    }

    func startProcessing() {
        frameProcessor.process()
    }
}

func main() {
    let handler = DataHandler()
    handler.loadData()
    handler.startProcessing()
}

main()