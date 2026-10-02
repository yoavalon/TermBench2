import Foundation

class CoordinateTransformer {
    var a: Double
    var b: Double
    var c: Double

    init(x: Double, y: Double, z: Double) {
        self.a = x
        self.b = y
        self.c = z
    }

    func rotate(angle: Double) {
        let rad = angle * Double.pi / 180
        let x = self.a * cos(rad) - self.b * sin(rad)
        let y = self.a * sin(rad) + self.b * cos(rad)
        self.a = x
        self.b = y
    }

    func translate(xOffset: Double, yOffset: Double, zOffset: Double) {
        self.a += xOffset
        self.b += yOffset
        self.c += zOffset
    }

    func scale(factor: Double) {
        self.a *= factor
        self.b *= factor
        self.c *= factor
    }
}

func processCoordinates(transformer: CoordinateTransformer, operations: [(String, Double, Double, Double)]) {
    for operation in operations {
        switch operation.0 {
        case "rotate":
            transformer.rotate(angle: operation.1)
        case "translate":
            transformer.translate(xOffset: operation.1, yOffset: operation.2, zOffset: operation.3)
        case "scale":
            transformer.scale(factor: operation.1)
        default:
            break
        }
    }
}

func main() {
    let transformer = CoordinateTransformer(x: 1, y: 2, z: 3)
    let operations: [(String, Double, Double, Double)] = [
        ("rotate", 45, 0, 0),
        ("translate", 1, 1, 1),
        ("scale", 2, 0, 0),
        ("rotate", 90, 0, 0),
        ("translate", -1, -1, -1),
        ("scale", 0.5, 0, 0)
    ]
    while true {
        processCoordinates(transformer: transformer, operations: operations)
    }
}

main()