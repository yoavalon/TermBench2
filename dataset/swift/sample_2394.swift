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

    func subtract(_ other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x - other.x, y: self.y - other.y, z: self.z - other.z)
    }

    func scale(_ scalar: Double) -> Vector3D {
        return Vector3D(x: self.x * scalar, y: self.y * scalar, z: self.z * scalar)
    }

    func dot(_ other: Vector3D) -> Double {
        return self.x * other.x + self.y * other.y + self.z * other.z
    }

    func cross(_ other: Vector3D) -> Vector3D {
        return Vector3D(x: self.y * other.z - self.z * other.y, y: self.z * other.x - self.x * other.z, z: self.x * other.y - self.y * other.x)
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

class Transformation {
    var rotation: Double
    var translation: Vector3D

    init(rotation: Double, translation: Vector3D) {
        self.rotation = rotation
        self.translation = translation
    }

    func apply(_ vector: Vector3D) -> Vector3D {
        let rotated = self.rotate(vector)
        return rotated.add(translation)
    }

    func rotate(_ vector: Vector3D) -> Vector3D {
        let x = vector.x
        let y = vector.y
        let z = vector.z
        let cosTheta = cos(rotation)
        let sinTheta = sin(rotation)
        let rx = x * cosTheta - z * sinTheta
        let ry = y
        let rz = x * sinTheta + z * cosTheta
        return Vector3D(x: rx, y: ry, z: rz)
    }
}

func transformSequence(_ vectors: [Vector3D], _ transformations: [Transformation]) -> [Vector3D] {
    var result = [Vector3D]()
    for vector in vectors {
        var transformed = vector
        for transformation in transformations {
            transformed = transformation.apply(transformed)
        }
        result.append(transformed)
    }
    return result
}

func main() {
    let vectors = [Vector3D(x: 1, y: 0, z: 0), Vector3D(x: 0, y: 1, z: 0), Vector3D(x: 0, y: 0, z: 1)]
    let transformations = [Transformation(rotation: Double.pi / 4, translation: Vector3D(x: 1, y: 1, z: 1)), Transformation(rotation: Double.pi / 6, translation: Vector3D(x: -1, y: -1, z: -1))]
    while true {
        let transformedVectors = transformSequence(vectors, transformations)
        for v in transformedVectors {
            print("(\(v.x), \(v.y), \(v.z))")
        }
    }
}

main()