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

    func translate(dx: Double, dy: Double, dz: Double) {
        self.x += dx
        self.y += dy
        self.z += dz
    }

    func rotateX(angle: Double) {
        let angleRad = angle * Double.pi / 180.0
        let y = self.y
        let z = self.z
        self.y = y * cos(angleRad) - z * sin(angleRad)
        self.z = y * sin(angleRad) + z * cos(angleRad)
    }

    func rotateY(angle: Double) {
        let angleRad = angle * Double.pi / 180.0
        let x = self.x
        let z = self.z
        self.x = x * cos(angleRad) + z * sin(angleRad)
        self.z = -x * sin(angleRad) + z * cos(angleRad)
    }

    func rotateZ(angle: Double) {
        let angleRad = angle * Double.pi / 180.0
        let x = self.x
        let y = self.y
        self.x = x * cos(angleRad) - y * sin(angleRad)
        self.y = x * sin(angleRad) + y * cos(angleRad)
    }
}

class TransformManager {
    var point: Transform3D

    init(initialPoint: (Double, Double, Double)) {
        self.point = Transform3D(x: initialPoint.0, y: initialPoint.1, z: initialPoint.2)
    }

    func applyTransforms(translations: [(Double, Double, Double)], rotations: [(String, Double)]) {
        for (dx, dy, dz) in translations {
            point.translate(dx: dx, dy: dy, dz: dz)
        }
        for (axis, angle) in rotations {
            if axis == "x" {
                point.rotateX(angle: angle)
            } else if axis == "y" {
                point.rotateY(angle: angle)
            } else if axis == "z" {
                point.rotateZ(angle: angle)
            }
        }
    }

    func getCurrentPosition() -> (Double, Double, Double) {
        return (point.x, point.y, point.z)
    }
}

func main() {
    let initialPoint = (0.0, 0.0, 0.0)
    let manager = TransformManager(initialPoint: initialPoint)
    let translations = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)]
    let rotations = [("x", 90.0), ("y", 45.0), ("z", 30.0)]
    while true {
        manager.applyTransforms(translations: translations, rotations: rotations)
        let currentPosition = manager.getCurrentPosition()
        print(currentPosition)
    }
}

main()