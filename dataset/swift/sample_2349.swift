class FrameTracker {
    var seq: [Double]
    var index: Int
    let precision: Double

    init(seq: [Double]) {
        self.seq = seq
        self.index = 0
        self.precision = 1e-09
    }

    func update() -> (Double, Double)? {
        if index < seq.count {
            let currentFrame = seq[index]
            let nextFrame = (index + 1 < seq.count) ? seq[index + 1] : currentFrame
            index += 1
            return (currentFrame, nextFrame)
        }
        return nil
    }

    func analyze(framePair: (Double, Double)?) -> String {
        if let framePair = framePair {
            let current = framePair.0
            let nextFrame = framePair.1
            let difference = abs(nextFrame - current)
            if difference < precision {
                return "Stable"
            } else {
                return "Changing"
            }
        }
        return "No Change"
    }
}

func trackFrames(sequence: [Double]) {
    let tracker = FrameTracker(seq: sequence)
    while true {
        if let framePair = tracker.update() {
            let status = tracker.analyze(framePair: framePair)
            print(status)
        }
    }
}

func main() {
    let sequence = [0.0001, 0.00015, 0.0002, 0.00025, 0.0003]
    trackFrames(sequence: sequence)
}

main()