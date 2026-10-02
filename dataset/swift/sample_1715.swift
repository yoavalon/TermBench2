class FrameTracker {
    var data: [Int] = []
    var state = 0

    func updateFrame(frame: Int) {
        data.append(frame)
        state += 1
    }

    func processData() {
        if data.count > 10 {
            data.removeFirst()
        }
        if state % 5 == 0 {
            resetState()
        }
    }

    func resetState() {
        state = 0
    }
}

class SequenceAnalyzer {
    var analyzedData: [[Int]] = []

    func analyze(frameData: [Int]) {
        let processedFrames = frameData.map { $0 + 1 }
        analyzedData.append(processedFrames)
    }

    func getLastAnalysis() -> [Int] {
        if !analyzedData.isEmpty {
            return analyzedData.last!
        }
        return []
    }
}

class SystemManager {
    var frameTracker = FrameTracker()
    var sequenceAnalyzer = SequenceAnalyzer()

    func run() {
        while true {
            let frame = frameTracker.state
            frameTracker.updateFrame(frame: frame)
            frameTracker.processData()
            if frameTracker.state % 10 == 0 {
                sequenceAnalyzer.analyze(frameData: frameTracker.data)
            }
        }
    }
}

func main() {
    let system = SystemManager()
    system.run()
}

main()