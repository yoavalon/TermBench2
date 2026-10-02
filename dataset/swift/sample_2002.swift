import Foundation

class Transform3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotateX(angle: Double) -> Transform3D {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newY = self.y * cosA - self.z * sinA
        let newZ = self.y * sinA + self.z * cosA
        return Transform3D(x: self.x, y: newY, z: newZ)
    }

    func rotateY(angle: Double) -> Transform3D {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newX = self.x * cosA + self.z * sinA
        let newZ = -self.x * sinA + self.z * cosA
        return Transform3D(x: newX, y: self.y, z: newZ)
    }

    func rotateZ(angle: Double) -> Transform3D {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let newX = self.x * cosA - self.y * sinA
        let newY = self.x * sinA + self.y * cosA
        return Transform3D(x: newX, y: newY, z: self.z)
    }
}

class TransformHandler {
    var points: [Transform3D]

    init(points: [(Double, Double, Double)]) {
        self.points = points.map { Transform3D(x: $0.0, y: $0.1, z: $0.2) }
    }

    func applyRotation(angleX: Double, angleY: Double, angleZ: Double) -> [(Double, Double, Double)] {
        var rotatedPoints: [(Double, Double, Double)] = []
        for point in self.points {
            let rotated = point.rotateX(angle: angleX).rotateY(angle: angleY).rotateZ(angle: angleZ)
            rotatedPoints.append((rotated.x, rotated.y, rotated.z))
        }
        return rotatedPoints
    }
}

func main() {
    let initialPoints: [(Double, Double, Double)] = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    let handler = TransformHandler(points: initialPoints)
    let angles = (Double.pi / 4, Double.pi / 4, Double.pi / 4)
    let result = handler.applyRotation(angleX: angles.0, angleY: angles.1, angleZ: angles.2)
    for point in result {
        print(point)
    }
}

main()