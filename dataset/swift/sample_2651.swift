class Vector3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func add(other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func subtract(other: Vector3D) -> Vector3D {
        return Vector3D(x: self.x - other.x, y: self.y - other.y, z: self.z - other.z)
    }

    func scale(scalar: Double) -> Vector3D {
        return Vector3D(x: self.x * scalar, y: self.y * scalar, z: self.z * scalar)
    }

    func magnitude() -> Double {
        return (self.x * self.x + self.y * self.y + self.z * self.z).squareRoot()
    }
}

class Transformation {
    var rotationMatrix: [[Double]]
    var translationVector: Vector3D

    init(rotationMatrix: [[Double]], translationVector: Vector3D) {
        self.rotationMatrix = rotationMatrix
        self.translationVector = translationVector
    }

    func apply(vector: Vector3D) -> Vector3D {
        let x = vector.x * rotationMatrix[0][0] + vector.y * rotationMatrix[0][1] + vector.z * rotationMatrix[0][2]
        let y = vector.x * rotationMatrix[1][0] + vector.y * rotationMatrix[1][1] + vector.z * rotationMatrix[1][2]
        let z = vector.x * rotationMatrix[2][0] + vector.y * rotationMatrix[2][1] + vector.z * rotationMatrix[2][2]
        let translatedVector = Vector3D(x: x, y: y, z: z).add(other: translationVector)
        return translatedVector
    }
}

func generateSequence(start: Vector3D, transformation: Transformation, steps: Int) -> [Vector3D] {
    var sequence: [Vector3D] = []
    var currentVector = start
    for _ in 0..<steps {
        sequence.append(currentVector)
        currentVector = transformation.apply(vector: currentVector)
    }
    return sequence
}

func main() {
    let startVector = Vector3D(x: 1, y: 0, z: 0)
    let rotationMatrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]]
    let translationVector = Vector3D(x: 1, y: 1, z: 1)
    let transformation = Transformation(rotationMatrix: rotationMatrix, translationVector: translationVector)
    let sequence = generateSequence(start: startVector, transformation: transformation, steps: 10)
    for vector in sequence {
        print("(\(vector.x), \(vector.y), \(vector.z))")
    }
}

main()