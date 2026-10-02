import Foundation

class Point {
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

    func scale(sx: Double, sy: Double, sz: Double) {
        self.x *= sx
        self.y *= sy
        self.z *= sz
    }

    func rotateX(angle: Double) {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        self.y = self.y * cosAngle - self.z * sinAngle
        self.z = self.y * sinAngle + self.z * cosAngle
    }

    func rotateY(angle: Double) {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        self.x = self.x * cosAngle + self.z * sinAngle
        self.z = -self.x * sinAngle + self.z * cosAngle
    }

    func rotateZ(angle: Double) {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        self.x = self.x * cosAngle - self.y * sinAngle
        self.y = self.x * sinAngle + self.y * cosAngle
    }
}

class Transformation {
    var points: [Point]

    init(points: [Point]) {
        self.points = points
    }

    func applyTranslation(dx: Double, dy: Double, dz: Double) {
        for point in self.points {
            point.translate(dx: dx, dy: dy, dz: dz)
        }
    }

    func applyScale(sx: Double, sy: Double, sz: Double) {
        for point in self.points {
            point.scale(sx: sx, sy: sy, sz: sz)
        }
    }

    func applyRotationX(angle: Double) {
        for point in self.points {
            point.rotateX(angle: angle)
        }
    }

    func applyRotationY(angle: Double) {
        for point in self.points {
            point.rotateY(angle: angle)
        }
    }

    func applyRotationZ(angle: Double) {
        for point in self.points {
            point.rotateZ(angle: angle)
        }
    }
}

func main() {
    let points = [Point(x: 1, y: 2, z: 3), Point(x: 4, y: 5, z: 6), Point(x: 7, y: 8, z: 9)]
    let transformation = Transformation(points: points)
    transformation.applyTranslation(dx: 1, dy: 1, dz: 1)
    transformation.applyScale(sx: 2, sy: 2, sz: 2)
    transformation.applyRotationX(angle: 3.14159 / 4)
    transformation.applyRotationY(angle: 3.14159 / 4)
    transformation.applyRotationZ(angle: 3.14159 / 4)
    for point in points {
        print("(\(point.x), \(point.y), \(point.z))")
    }
}

main()