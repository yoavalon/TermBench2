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

    func rotate_x(angle: Double) -> Point3D {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        return Point3D(x: self.x, y: self.y * cos_a - self.z * sin_a, z: self.y * sin_a + self.z * cos_a)
    }

    func rotate_y(angle: Double) -> Point3D {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        return Point3D(x: self.x * cos_a + self.z * sin_a, y: self.y, z: -self.x * sin_a + self.z * cos_a)
    }

    func rotate_z(angle: Double) -> Point3D {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        return Point3D(x: self.x * cos_a - self.y * sin_a, y: self.x * sin_a + self.y * cos_a, z: self.z)
    }

    override var description: String {
        return "Point3D(\(self.x), \(self.y), \(self.z))"
    }
}

func transform_sequence(point: Point3D, operations: [(String, [Double])], index: Int = 0) -> Point3D {
    if index == operations.count {
        return point
    }
    let (operation, args) = operations[index]
    var newPoint = point
    if operation == "translate" {
        newPoint = point.translate(dx: args[0], dy: args[1], dz: args[2])
    } else if operation == "rotate_x" {
        newPoint = point.rotate_x(angle: args[0])
    } else if operation == "rotate_y" {
        newPoint = point.rotate_y(angle: args[0])
    } else if operation == "rotate_z" {
        newPoint = point.rotate_z(angle: args[0])
    }
    return transform_sequence(point: newPoint, operations: operations, index: index + 1)
}

func main() {
    let point = Point3D(x: 1, y: 2, z: 3)
    let operations: [(String, [Double])] = [("translate", [1, 1, 1]), ("rotate_x", [0.785398]), ("rotate_y", [0.785398]), ("rotate_z", [0.785398]), ("translate", [-1, -1, -1])]
    let finalPoint = transform_sequence(point: point, operations: operations)
    print(finalPoint)
}

main()