import Foundation

class CoordinateTransformer {
    var angle: Double
    var cosTheta: Double
    var sinTheta: Double

    init(angle: Double) {
        self.angle = angle
        self.cosTheta = cos(angle * Double.pi / 180)
        self.sinTheta = sin(angle * Double.pi / 180)
    }

    func transformPoint(x: Double, y: Double, z: Double) -> (Double, Double, Double) {
        let xPrime = x * cosTheta - y * sinTheta
        let yPrime = x * sinTheta + y * cosTheta
        let zPrime = z
        return (xPrime, yPrime, zPrime)
    }
}

class SequenceGenerator {
    var point: (Double, Double, Double)
    var transformer: CoordinateTransformer

    init(initialPoint: (Double, Double, Double), transformer: CoordinateTransformer) {
        self.point = initialPoint
        self.transformer = transformer
    }

    func generateNext() -> (Double, Double, Double) {
        self.point = transformer.transformPoint(x: point.0, y: point.1, z: point.2)
        return self.point
    }
}

class ContinuousSequencePrinter {
    var sequenceGenerator: SequenceGenerator

    init(sequenceGenerator: SequenceGenerator) {
        self.sequenceGenerator = sequenceGenerator
    }

    func printSequence() {
        while true {
            let nextPoint = sequenceGenerator.generateNext()
            print(nextPoint)
        }
    }
}

func main() {
    let angle = 45.0
    let initialPoint = (1.0, 0.0, 0.0)
    let transformer = CoordinateTransformer(angle: angle)
    let sequenceGenerator = SequenceGenerator(initialPoint: initialPoint, transformer: transformer)
    let continuousPrinter = ContinuousSequencePrinter(sequenceGenerator: sequenceGenerator)
    continuousPrinter.printSequence()
}

main()