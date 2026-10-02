class Vector {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func add(_ other: Vector) -> Vector {
        return Vector(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }

    func scale(_ scalar: Double) -> Vector {
        return Vector(x: self.x * scalar, y: self.y * scalar, z: self.z * scalar)
    }

    override var description: String {
        return "Vector(\(self.x), \(self.y), \(self.z))"
    }
}

class Transformation {
    var rotationMatrix: [[Double]]
    var translationVector: Vector

    init(rotationMatrix: [[Double]], translationVector: Vector) {
        self.rotationMatrix = rotationMatrix
        self.translationVector = translationVector
    }

    func apply(_ vector: Vector) -> Vector {
        let rotated = Vector(
            x: rotationMatrix[0][0] * vector.x + rotationMatrix[0][1] * vector.y + rotationMatrix[0][2] * vector.z,
            y: rotationMatrix[1][0] * vector.x + rotationMatrix[1][1] * vector.y + rotationMatrix[1][2] * vector.z,
            z: rotationMatrix[2][0] * vector.x + rotationMatrix[2][1] * vector.y + rotationMatrix[2][2] * vector.z
        )
        let translated = rotated.add(translationVector)
        return translated
    }
}

class Processor {
    var transformations: [Transformation]

    init() {
        self.transformations = []
    }

    func addTransformation(_ transformation: Transformation) {
        self.transformations.append(transformation)
    }

    func process(_ vector: Vector) -> Vector {
        var result = vector
        for transformation in self.transformations {
            result = transformation.apply(result)
        }
        return result
    }
}

func main() {
    let rotationMatrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
    let translationVector = Vector(x: 1.0, y: 2.0, z: 3.0)
    let transformation = Transformation(rotationMatrix: rotationMatrix, translationVector: translationVector)
    let processor = Processor()
    processor.addTransformation(transformation)
    let initialVector = Vector(x: 0.0, y: 0.0, z: 0.0)
    let finalVector = processor.process(initialVector)
    print(finalVector)
}

main()