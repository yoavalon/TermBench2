import Foundation

class CoordinateSystem {
    var origin = (0.0, 0.0, 0.0)

    func transform(_ vector: (Double, Double, Double), scale: Double = 1.0) -> (Double, Double, Double) {
        let (x, y, z) = vector
        return (x * scale, y * scale, z * scale)
    }

    func rotate(_ vector: (Double, Double, Double), angle: Double) -> (Double, Double, Double) {
        let (x, y, z) = vector
        let cosA = cos(angle)
        let sinA = sin(angle)
        return (x * cosA - y * sinA, x * sinA + y * cosA, z)
    }
}

class TransformationManager {
    var coordinateSystem = CoordinateSystem()

    func applyTransformations(_ vector: (Double, Double, Double), scale: Double, angle: Double) -> (Double, Double, Double) {
        let scaledVector = coordinateSystem.transform(vector, scale: scale)
        let rotatedVector = coordinateSystem.rotate(scaledVector, angle: angle)
        return rotatedVector
    }
}

class SimulationEngine {
    var manager = TransformationManager()
    var vector = (1.0, 1.0, 1.0)
    var scale = 2.0
    var angle = 0.1

    func run() {
        while true {
            let result = manager.applyTransformations(vector, scale: scale, angle: angle)
            vector = result
            angle += 0.01
        }
    }
}

func main() {
    let engine = SimulationEngine()
    engine.run()
}

main()