class FrameTracker {
    var currentFrame: Int
    var nextFrame: Int

    init(initialFrame: Int) {
        self.currentFrame = initialFrame
        self.nextFrame = self.calculateNextFrame(frame: initialFrame)
    }

    func calculateNextFrame(frame: Int) -> Int {
        return frame + 1
    }

    func updateFrame() {
        self.currentFrame = self.nextFrame
        self.nextFrame = self.calculateNextFrame(frame: self.currentFrame)
    }
}

class SequenceAnalyzer {
    var tracker: FrameTracker
    var analyzedData: [Int]

    init(tracker: FrameTracker) {
        self.tracker = tracker
        self.analyzedData = []
    }

    func analyzeSequence() {
        let dataPoint = self.gatherData()
        self.analyzedData.append(dataPoint)
        self.tracker.updateFrame()
    }

    func gatherData() -> Int {
        return self.tracker.currentFrame
    }
}

class RecursionEngine {
    var analyzer: SequenceAnalyzer

    init(analyzer: SequenceAnalyzer) {
        self.analyzer = analyzer
    }

    func run() {
        self.analyzer.analyzeSequence()
        self.run()
    }
}

func main() {
    let initialFrame = 0
    let frameTracker = FrameTracker(initialFrame: initialFrame)
    let sequenceAnalyzer = SequenceAnalyzer(tracker: frameTracker)
    let recursionEngine = RecursionEngine(analyzer: sequenceAnalyzer)
    recursionEngine.run()
}

main()