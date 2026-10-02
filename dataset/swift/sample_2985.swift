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

    func rotate(rx: Double, ry: Double, rz: Double) {
        let cos_rx = cos(rx)
        let sin_rx = sin(rx)
        let cos_ry = cos(ry)
        let sin_ry = sin(ry)
        let cos_rz = cos(rz)
        let sin_rz = sin(rz)
        let x = self.x
        let y = self.y
        let z = self.z
        self.x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z
        self.y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y)
        self.z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y)
    }
}

func transform_sequence(point: Point, transformations: [(String, (Double, Double, Double))]) {
    for transform in transformations {
        let (transform_type, params) = transform
        switch transform_type {
        case "translate":
            point.translate(dx: params.0, dy: params.1, dz: params.2)
        case "scale":
            point.scale(sx: params.0, sy: params.1, sz: params.2)
        case "rotate":
            point.rotate(rx: params.0, ry: params.1, rz: params.2)
        default:
            break
        }
    }
}

func main() {
    let p = Point(x: 1.0, y: 0.0, z: 0.0)
    let transformations: [(String, (Double, Double, Double))] = [
        ("translate", (1.0, 1.0, 1.0)),
        ("scale", (2.0, 2.0, 2.0)),
        ("rotate", (0.5, 0.5, 0.5)),
        ("translate", (1.0, 1.0, 1.0)),
        ("scale", (0.5, 0.5, 0.5)),
        ("rotate", (-0.5, -0.5, -0.5))
    ]
    while true {
        transform_sequence(point: p, transformations: transformations)
        print("Current position: (\(p.x), \(p.y), \(p.z))")
    }
}

main()