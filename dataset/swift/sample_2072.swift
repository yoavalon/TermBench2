import Foundation

class Point3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func translate(dx: Double, dy: Double, dz: Double) -> Point3D {
        return Point3D(x: self.x + dx, y: self.y + dy, z: self.z + dz)
    }

    func scale(sx: Double, sy: Double, sz: Double) -> Point3D {
        return Point3D(x: self.x * sx, y: self.y * sy, z: self.z * sz)
    }

    func rotate_x(angle: Double) -> Point3D {
        let c = cos(angle)
        let s = sin(angle)
        return Point3D(x: self.x, y: self.y * c - self.z * s, z: self.y * s + self.z * c)
    }

    func rotate_y(angle: Double) -> Point3D {
        let c = cos(angle)
        let s = sin(angle)
        return Point3D(x: self.x * c + self.z * s, y: self.y, z: -self.x * s + self.z * c)
    }

    func rotate_z(angle: Double) -> Point3D {
        let c = cos(angle)
        let s = sin(angle)
        return Point3D(x: self.x * c - self.y * s, y: self.x * s + self.y * c, z: self.z)
    }
}

class Transformation {
    var point: Point3D

    init(point: Point3D) {
        self.point = point
    }

    func apply_transformations(translations: [(Double, Double, Double)], scalings: [(Double, Double, Double)], rotations: [Double]) {
        for (dx, dy, dz) in translations {
            self.point = self.point.translate(dx: dx, dy: dy, dz: dz)
        }
        for (sx, sy, sz) in scalings {
            self.point = self.point.scale(sx: sx, sy: sy, sz: sz)
        }
        for angle in rotations {
            self.point = self.point.rotate_x(angle: angle)
            self.point = self.point.rotate_y(angle: angle)
            self.point = self.point.rotate_z(angle: angle)
        }
    }

    func get_final_position() -> (Double, Double, Double) {
        return (self.point.x, self.point.y, self.point.z)
    }
}

func main() {
    let initial_point = Point3D(x: 1.0, y: 2.0, z: 3.0)
    let transformations = Transformation(point: initial_point)
    let translations: [(Double, Double, Double)] = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0)]
    let scalings: [(Double, Double, Double)] = [(2.0, 2.0, 2.0)]
    let rotations: [Double] = [0.785398163]
    transformations.apply_transformations(translations: translations, scalings: scalings, rotations: rotations)
    let final_position = transformations.get_final_position()
    print(final_position)
}

main()