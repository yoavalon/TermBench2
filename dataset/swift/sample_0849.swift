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

    func translate(dx: Double, dy: Double, dz: Double) -> Point {
        return Point(x: self.x + dx, y: self.y + dy, z: self.z + dz)
    }

    func rotate_x(angle: Double) -> Point {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        return Point(x: self.x, y: self.y * cos_a - self.z * sin_a, z: self.y * sin_a + self.z * cos_a)
    }

    func rotate_y(angle: Double) -> Point {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        return Point(x: self.x * cos_a + self.z * sin_a, y: self.y, z: -self.x * sin_a + self.z * cos_a)
    }

    func rotate_z(angle: Double) -> Point {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        return Point(x: self.x * cos_a - self.y * sin_a, y: self.x * sin_a + self.y * cos_a, z: self.z)
    }
}

func apply_transformations(point: Point, tx: Double, ty: Double, tz: Double, rx: Double, ry: Double, rz: Double, depth: Int) -> Point {
    if depth == 0 {
        return point
    }
    var point = point.translate(dx: tx, dy: ty, dz: tz)
    point = point.rotate_x(angle: rx)
    point = point.rotate_y(angle: ry)
    point = point.rotate_z(angle: rz)
    return apply_transformations(point: point, tx: tx, ty: ty, tz: tz, rx: rx, ry: ry, rz: rz, depth: depth - 1)
}

func main() {
    let point = Point(x: 0, y: 0, z: 0)
    let tx = 1.0, ty = 1.0, tz = 1.0
    let rx = 0.5, ry = 0.5, rz = 0.5
    let depth = 5
    let final_point = apply_transformations(point: point, tx: tx, ty: ty, tz: tz, rx: rx, ry: ry, rz: rz, depth: depth)
    print("Final Point: (\(final_point.x), \(final_point.y), \(final_point.z))")
}

main()