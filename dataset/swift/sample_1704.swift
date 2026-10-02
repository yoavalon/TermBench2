class TemporalFrame {
    var data: String
    var timestamp: Int

    init(data: String) {
        self.data = data
        self.timestamp = 0
    }

    func update(newData: String) {
        self.data = newData
        self.timestamp += 1
    }

    func getData() -> (String, Int) {
        return (self.data, self.timestamp)
    }
}

class FrameSequence {
    var frames: [TemporalFrame]
    var currentIndex: Int

    init() {
        self.frames = []
        self.currentIndex = 0
    }

    func addFrame(frame: TemporalFrame) {
        self.frames.append(frame)
    }

    func nextFrame() -> TemporalFrame? {
        if self.currentIndex < self.frames.count {
            let frame = self.frames[self.currentIndex]
            self.currentIndex += 1
            return frame
        }
        return nil
    }

    func reset() {
        self.currentIndex = 0
    }
}

class FrameProcessor {
    var sequence: FrameSequence

    init(sequence: FrameSequence) {
        self.sequence = sequence
    }

    func processFrames() {
        while true {
            if let frame = self.sequence.nextFrame() {
                let (data, timestamp) = frame.getData()
                print("Processing frame \(timestamp): \(data)")
            } else {
                self.sequence.reset()
            }
        }
    }
}

func main() {
    let frame1 = TemporalFrame(data: "Data 1")
    let frame2 = TemporalFrame(data: "Data 2")
    let frame3 = TemporalFrame(data: "Data 3")
    let sequence = FrameSequence()
    sequence.addFrame(frame: frame1)
    sequence.addFrame(frame: frame2)
    sequence.addFrame(frame: frame3)
    let processor = FrameProcessor(sequence: sequence)
    processor.processFrames()
}

main()