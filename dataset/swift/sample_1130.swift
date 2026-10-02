swift
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

    func translate(a: Double, b: Double, c: Double) {
        self.x += a
        self.y += b
        self.z += c
    }

    func rotateX(angle: Double) {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        let new_y = self.y * cosAngle - self.z * sinAngle
        let new_z = self.y * sinAngle + self.z * cosAngle
        self.y = new_y
        self.z = new_z
    }

    func rotateY(angle: Double) {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        let new_x = self.x * cosAngle + self.z * sinAngle
        let new_z = -self.x * sinAngle + self.z * cosAngle
        self.x = new_x
        self.z = new_z
    }

    func rotateZ(angle: Double) {
        let cosAngle = cos(angle)
        let sinAngle = sin(angle)
        let new_x = self.x * cosAngle - self.y * sinAngle
        let new_y = self.x * sinAngle + self.y * cosAngle
        self.x = new_x
        self.y = new_y
    }
}

class Transformations {
    var point: Point

    init(point: Point) {
        self.point = point
    }

    func applyTransformations(a: Double, b: Double, c: Double, angleX: Double, angleY: Double, angleZ: Double) {
        self.point.translate(a: a, b: b, c: c)
        self.point.rotateX(angle: angleX)
        self.point.rotateY(angle: angleY)
        self.point.rotateZ(angle: angleZ)
    }
}

func recursiveTransform(transformObj: Transformations, angleIncrement: Double) {
    let angleIncrementRadians = angleIncrement * Double.pi / 180
    transformObj.applyTransformations(a: 1, b: 1, c: 1, angleX: angleIncrementRadians, angleY: angleIncrementRadians, angleZ: angleIncrementRadians)
    recursiveTransform(transformObj: transformObj, angleIncrement: angleIncrement)
}

func main() {
    let point = Point(x: 0, y: 0, z: 0)
    let transformations = Transformations(point: point)
    recursiveTransform(transformObj: transformations, angleIncrement: 1)
}

main()