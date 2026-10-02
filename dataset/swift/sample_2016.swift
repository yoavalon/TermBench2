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

    override var description: String {
        return "Point(\(x), \(y), \(z))"
    }
}

class Transformation {
    func rotate(point: Point, angle_x: Double, angle_y: Double, angle_z: Double) -> Point {
        let cos_x = cos(angle_x)
        let sin_x = sin(angle_x)
        let cos_y = cos(angle_y)
        let sin_y = sin(angle_y)
        let cos_z = cos(angle_z)
        let sin_z = sin(angle_z)
        let x = point.x * (cos_y * cos_z) + point.y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point.z * (cos_y * sin_x * sin_z + cos_x * cos_z)
        let y = point.x * (sin_y * cos_z) + point.y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point.z * (sin_y * sin_x * sin_z - cos_x * sin_z)
        let z = point.x * (-sin_x * cos_y) + point.y * (sin_x * sin_y) + point.z * cos_x
        return Point(x: x, y: y, z: z)
    }

    func translate(point: Point, dx: Double, dy: Double, dz: Double) -> Point {
        return Point(x: point.x + dx, y: point.y + dy, z: point.z + dz)
    }

    func scale(point: Point, sx: Double, sy: Double, sz: Double) -> Point {
        return Point(x: point.x * sx, y: point.y * sy, z: point.z * sz)
    }
}

class CoordinateSystem {
    var origin: Point
    var transformation: Transformation

    init(origin: Point, transformation: Transformation) {
        self.origin = origin
        self.transformation = transformation
    }

    func applyTransformations(point: Point, angle_x: Double, angle_y: Double, angle_z: Double, dx: Double, dy: Double, dz: Double, sx: Double, sy: Double, sz: Double) -> Point {
        var point = self.transformation.rotate(point: point, angle_x: angle_x, angle_y: angle_y, angle_z: angle_z)
        point = self.transformation.translate(point: point, dx: dx, dy: dy, dz: dz)
        point = self.transformation.scale(point: point, sx: sx, sy: sy, sz: sz)
        return point
    }
}

func main() {
    let origin = Point(x: 0, y: 0, z: 0)
    let transformation = Transformation()
    let coordinate_system = CoordinateSystem(origin: origin, transformation: transformation)
    let initial_point = Point(x: 1, y: 2, z: 3)
    let angle_x = 0.5
    let angle_y = 0.5
    let angle_z = 0.5
    let dx = 1.0
    let dy = 1.0
    let dz = 1.0
    let sx = 2.0
    let sy = 2.0
    let sz = 2.0
    let transformed_point = coordinate_system.applyTransformations(point: initial_point, angle_x: angle_x, angle_y: angle_y, angle_z: angle_z, dx: dx, dy: dy, dz: dz, sx: sx, sy: sy, sz: sz)
    print(transformed_point)
}

main()