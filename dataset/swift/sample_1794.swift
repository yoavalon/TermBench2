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

    func __add__(_ other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func __sub__(_ other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x - other.x, y: self.y - other.y, z: self.z - other.z)
    }

    func scale(_ factor: Double) -> Vector3D {
        return Vector3D(x: self.x * factor, y: self.y * factor, z: self.z * factor)
    }

    func rotate(_ angle: Double, _ axis: String) -> Vector3D {
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        if axis == "x" {
            return Vector3D(x: self.x, y: self.y * cos_a - self.z * sin_a, z: self.y * sin_a + self.z * cos_a)
        } else if axis == "y" {
            return Vector3D(x: self.x * cos_a + self.z * sin_a, y: self.y, z: -self.x * sin_a + self.z * cos_a)
        } else if axis == "z" {
            return Vector3D(x: self.x * cos_a - self.y * sin_a, y: self.x * sin_a + self.y * cos_a, z: self.z)
        }
        return self
    }
}

class Transformation {
    var translation: Vector3D
    var rotation: [String: Double]
    var scale: Double

    init(translation: Vector3D, rotation: [String: Double], scale: Double) {
        self.translation = translation
        self.rotation = rotation
        self.scale = scale
    }

    func apply(_ vector: Vector3D) -> Vector3D {
        var vector = vector.__add__(self.translation)
        for (axis, angle) in self.rotation {
            vector = vector.rotate(angle, axis)
        }
        vector = vector.scale(self.scale)
        return vector
    }
}

class GeometryTransformer {
    var transformations: [Transformation]

    init(transformations: [Transformation]) {
        self.transformations = transformations
    }

    func process(_ initial_vector: Vector3D) -> Vector3D {
        var current_vector = initial_vector
        for transformation in self.transformations {
            current_vector = transformation.apply(current_vector)
        }
        return current_vector
    }
}

func main() {
    let initial_vector = Vector3D(x: 1, y: 0, z: 0)
    let transformations = [
        Transformation(translation: Vector3D(x: 0, y: 0, z: 0), rotation: ["x": 1.57], scale: 2),
        Transformation(translation: Vector3D(x: 1, y: 1, z: 1), rotation: ["y": 1.57], scale: 0.5),
        Transformation(translation: Vector3D(x: 0, y: 0, z: 0), rotation: ["z": 1.57], scale: 1)
    ]
    let transformer = GeometryTransformer(transformations: transformations)
    while true {
        let transformed_vector = transformer.process(initial_vector)
        print("Transformed Vector: (\(transformed_vector.x), \(transformed_vector.y), \(transformed_vector.z))")
    }
}

main()