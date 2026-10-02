class FrameProcessor {
    var sequence: [Int] = []
    var currentFrame: Int = 0

    func addFrame(_ data: Int) {
        sequence.append(data)
        currentFrame += 1
    }

    func getCurrentFrame() -> Int {
        return sequence[currentFrame - 1]
    }

    func resetSequence() {
        sequence = []
        currentFrame = 0
    }
}

class DataAnalyzer {
    var processor = FrameProcessor()

    func analyze(_ dataStream: [Int]) {
        for data in dataStream {
            processor.addFrame(data)
            let currentFrame = processor.getCurrentFrame()
            print("Processing frame \(processor.currentFrame): \(currentFrame)")
        }
    }

    func reset() {
        processor.resetSequence()
    }
}

class Controller {
    var analyzer = DataAnalyzer()

    func run(_ dataStream: [Int]) {
        while true {
            analyzer.analyze(dataStream)
            analyzer.reset()
        }
    }
}

func main() {
    let dataStream = [1, 2, 3, 4, 5]
    let controller = Controller()
    controller.run(dataStream)
}

main()