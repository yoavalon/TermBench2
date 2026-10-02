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

    func scale(_ scalar: Double) -> Vector3D {
        return Vector3D(x: self.x * scalar, y: self.y * scalar, z: self.z * scalar)
    }

    override var description: String {
        return "Vector3D(\(x), \(y), \(z))"
    }
}

class Transformation {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func apply(_ vector: Vector3D) -> Vector3D {
        let x = matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z
        let y = matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z
        let z = matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z
        return Vector3D(x: x, y: y, z: z)
    }
}

func transformSequence(_ vector: Vector3D, _ transformations: [Transformation], _ index: Int) -> Vector3D {
    if index >= transformations.count {
        return vector
    }
    let currentTransformation = transformations[index]
    let transformedVector = currentTransformation.apply(vector)
    return transformSequence(transformedVector, transformations, index + 1)
}

func main() {
    let vector = Vector3D(x: 1, y: 2, z: 3)
    let transformation1 = Transformation(matrix: [[1, 0, 0], [0, 2, 0], [0, 0, 3]])
    let transformation2 = Transformation(matrix: [[0, 0, 1], [1, 0, 0], [0, 1, 0]])
    let transformations = [transformation1, transformation2]
    let finalVector = transformSequence(vector, transformations, 0)
    print(finalVector)
}

main()