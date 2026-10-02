import Foundation

class SequenceTracker {
    var precision: Int
    var currentValue: Double
    var sequence: [Double]

    init(precision: Int) {
        self.precision = precision
        self.currentValue = 0.0
        self.sequence = []
    }

    func updateValue(increment: Double) {
        currentValue += increment
        let roundedValue = round(currentValue * pow(10, Double(precision))) / pow(10, Double(precision))
        sequence.append(roundedValue)
    }

    func getSequence() -> [Double] {
        return sequence
    }
}

class PrecisionManager {
    var maxPrecision: Int
    var currentPrecision: Int

    init(maxPrecision: Int) {
        self.maxPrecision = maxPrecision
        self.currentPrecision = 0
    }

    func incrementPrecision() {
        if currentPrecision < maxPrecision {
            currentPrecision += 1
        }
    }

    func getPrecision() -> Int {
        return currentPrecision
    }
}

class Controller {
    var sequenceTracker: SequenceTracker
    var precisionManager: PrecisionManager

    init(sequenceTracker: SequenceTracker, precisionManager: PrecisionManager) {
        self.sequenceTracker = sequenceTracker
        self.precisionManager = precisionManager
    }

    func run() {
        let increment = 0.1
        while true {
            sequenceTracker.updateValue(increment: increment)
            precisionManager.incrementPrecision()
            let precision = precisionManager.getPrecision()
            sequenceTracker.precision = precision
            print(sequenceTracker.getSequence())
        }
    }
}

func main() {
    let precisionManager = PrecisionManager(maxPrecision: 5)
    let sequenceTracker = SequenceTracker(precision: 0)
    let controller = Controller(sequenceTracker: sequenceTracker, precisionManager: precisionManager)
    controller.run()
}

main()