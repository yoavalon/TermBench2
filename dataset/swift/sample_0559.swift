import Foundation

class Vector3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func add(_ other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func multiply(by scalar: Double) -> Vector3D {
        return Vector3D(x: self.x * scalar, y: self.y * scalar, z: self.z * scalar)
    }

    func magnitude() -> Double {
        return sqrt(self.x * self.x + self.y * self.y + self.z * self.z)
    }

    func normalize() -> Vector3D {
        let mag = self.magnitude()
        if mag > 0 {
            return Vector3D(x: self.x / mag, y: self.y / mag, z: self.z / mag)
        }
        return Vector3D(x: 0, y: 0, z: 0)
    }
}

class Transform3D {
    var rotation: Double
    var translation: Vector3D

    init(rotation: Double, translation: Vector3D) {
        self.rotation = rotation
        self.translation = translation
    }

    func apply(to vector: Vector3D) -> Vector3D {
        let rotated = self.rotate(vector)
        return rotated.add(self.translation)
    }

    func rotate(_ vector: Vector3D) -> Vector3D {
        let cosTheta = cos(self.rotation)
        let sinTheta = sin(self.rotation)
        let x = vector.x * cosTheta - vector.y * sinTheta
        let y = vector.x * sinTheta + vector.y * cosTheta
        let z = vector.z
        return Vector3D(x: x, y: y, z: z)
    }
}

func generatePoints(count: Int, transform: Transform3D) -> [Vector3D] {
    var points = [Vector3D]()
    for i in 0..<count {
        let vector = Vector3D(x: Double(i), y: Double(i), z: Double(i))
        let transformed = transform.apply(to: vector)
        points.append(transformed)
    }
    return points
}

func main() {
    let rotation = Double.pi / 4
    let translation = Vector3D(x: 10, y: 20, z: 30)
    let transform = Transform3D(rotation: rotation, translation: translation)
    while true {
        let points = generatePoints(count: 100, transform: transform)
        for point in points {
            print("(\(point.x), \(point.y), \(point.z))")
        }
    }
}

main()