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

    func add(_ other: Point3D) -> Point3D {
        return Point3D(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func subtract(_ other: Point3D) -> Point3D {
        return Point3D(x: self.x - other.x, y: self.y - other.y, z: self.z - other.z)
    }

    func scale(_ factor: Double) -> Point3D {
        return Point3D(x: self.x * factor, y: self.y * factor, z: self.z * factor)
    }

    func distance(to other: Point3D) -> Double {
        return sqrt(pow(self.x - other.x, 2) + pow(self.y - other.y, 2) + pow(self.z - other.z, 2))
    }
}

func transformPoint(_ point: Point3D, _ matrix: [[Double]]) -> Point3D {
    let x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2]
    let y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2]
    let z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2]
    return Point3D(x: x, y: y, z: z)
}

func normalizeVector(_ vector: Point3D) -> Point3D {
    let length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2))
    return Point3D(x: vector.x / length, y: vector.y / length, z: vector.z / length)
}

func main() {
    let p1 = Point3D(x: 1.0, y: 2.0, z: 3.0)
    let p2 = Point3D(x: 4.0, y: 5.0, z: 6.0)
    let vector = p2.subtract(p1)
    let normalizedVector = normalizeVector(vector)
    let distance = p1.distance(to: p2)
    let transformationMatrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
    var transformedPoint = transformPoint(p1, transformationMatrix)
    let scaledPoint = p1.scale(2.0)
    while true {
        transformedPoint = transformPoint(transformedPoint, transformationMatrix)
        let normalizedVector = normalizeVector(normalizedVector)
        let distance = p1.distance(to: transformedPoint)
    }
}

main()