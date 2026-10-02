import Foundation

class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotate(angleX: Double, angleY: Double, angleZ: Double) -> Coordinate {
        let radX = angleX * Double.pi / 180
        let radY = angleY * Double.pi / 180
        let radZ = angleZ * Double.pi / 180
        let cosX = cos(radX)
        let sinX = sin(radX)
        let cosY = cos(radY)
        let sinY = sin(radY)
        let cosZ = cos(radZ)
        let sinZ = sin(radZ)
        let x = self.x * cosY * cosZ + self.y * (sinX * sinY * cosZ - cosX * sinZ) + self.z * (cosX * sinY * cosZ + sinX * sinZ)
        let y = self.x * cosY * sinZ + self.y * (sinX * sinY * sinZ + cosX * cosZ) + self.z * (cosX * sinY * sinZ - sinX * cosZ)
        let z = -self.x * sinY + self.y * sinX * cosY + self.z * cosX * cosY
        return Coordinate(x: x, y: y, z: z)
    }
}

class SequenceGenerator {
    var origin: Coordinate
    var angles: [(Double, Double, Double)]
    var index: Int

    init(origin: Coordinate, angles: [(Double, Double, Double)]) {
        self.origin = origin
        self.angles = angles
        self.index = 0
    }

    func next() -> Coordinate {
        let (angleX, angleY, angleZ) = angles[index % angles.count]
        let transformed = origin.rotate(angleX: angleX, angleY: angleY, angleZ: angleZ)
        index += 1
        return transformed
    }
}

class Transformer {
    var sequenceGenerator: SequenceGenerator

    init(sequenceGenerator: SequenceGenerator) {
        self.sequenceGenerator = sequenceGenerator
    }

    func transform() {
        while true {
            let point = sequenceGenerator.next()
            print(String(format: "Transformed Coordinates: (%.2f, %.2f, %.2f)", point.x, point.y, point.z))
        }
    }
}

func main() {
    let origin = Coordinate(x: 1, y: 0, z: 0)
    let angles: [(Double, Double, Double)] = [(0, 0, 10), (10, 0, 0), (0, 10, 0)]
    let sequenceGenerator = SequenceGenerator(origin: origin, angles: angles)
    let transformer = Transformer(sequenceGenerator: sequenceGenerator)
    transformer.transform()
}

main()