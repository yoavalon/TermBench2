import Foundation

class Transformation {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func apply(vector: [Double]) -> [Double] {
        var result = [0.0, 0.0, 0.0]
        for i in 0..<3 {
            for j in 0..<3 {
                result[i] += self.matrix[i][j] * vector[j]
            }
        }
        return result
    }
}

class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func toList() -> [Double] {
        return [self.x, self.y, self.z]
    }
}

func generateTransformationMatrix(angleX: Double, angleY: Double, angleZ: Double) -> [[Double]] {
    let cosX = cos(angleX)
    let sinX = sin(angleX)
    let cosY = cos(angleY)
    let sinY = sin(angleY)
    let cosZ = cos(angleZ)
    let sinZ = sin(angleZ)
    let matrix = [
        [cosY * cosZ, cosY * sinZ, -sinY],
        [sinX * sinY * cosZ - cosX * sinZ, sinX * sinY * sinZ + cosX * cosZ, sinX * cosY],
        [cosX * sinY * cosZ + sinX * sinZ, cosX * sinY * sinZ - sinX * cosZ, cosX * cosY]
    ]
    return matrix
}

func main() {
    let angleX = 0.1
    let angleY = 0.2
    let angleZ = 0.3
    let transformationMatrix = generateTransformationMatrix(angleX: angleX, angleY: angleY, angleZ: angleZ)
    let transformation = Transformation(matrix: transformationMatrix)
    var coordinate = Coordinate(x: 1.0, y: 2.0, z: 3.0)
    while true {
        let transformedVector = transformation.apply(vector: coordinate.toList())
        coordinate = Coordinate(x: transformedVector[0], y: transformedVector[1], z: transformedVector[2])
    }
}

main()