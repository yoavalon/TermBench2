swift
import Foundation

class CoordinateTransformer {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotateX(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newY = y * cosA - z * sinA
        let newZ = y * sinA + z * cosA
        y = newY
        z = newZ
    }

    func rotateY(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newX = x * cosA + z * sinA
        let newZ = -x * sinA + z * cosA
        x = newX
        z = newZ
    }

    func rotateZ(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newX = x * cosA - y * sinA
        let newY = x * sinA + y * cosA
        x = newX
        y = newY
    }

    func scale(factor: Double) {
        x *= factor
        y *= factor
        z *= factor
    }
}

func generateAngles() -> AnyIterator<Double> {
    var angle = 0.0
    return AnyIterator {
        defer { angle += Double.pi / 180 }
        return angle
    }
}

func transformSequence(transformer: CoordinateTransformer, angles: AnyIterator<Double>) {
    for angle in angles {
        transformer.rotateX(angle: angle)
        transformer.rotateY(angle: angle)
        transformer.rotateZ(angle: angle)
        transformer.scale(factor: 1.01)
    }
}

func main() {
    let transformer = CoordinateTransformer(x: 1, y: 0, z: 0)
    let angles = generateAngles()
    transformSequence(transformer: transformer, angles: angles)
}

main()