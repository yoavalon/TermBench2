func transformPoint(x: Double, y: Double, z: Double, matrix: [[Double]]) -> [Double] {
    return [
        x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2],
        x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2],
        x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]
    ]
}

func applySequenceTransformations(points: [(Double, Double, Double)], sequence: [[[Double]]]) -> [(Double, Double, Double)] {
    var result = points
    for matrix in sequence {
        var newPoints: [(Double, Double, Double)] = []
        for point in result {
            let transformed = transformPoint(x: point.0, y: point.1, z: point.2, matrix: matrix)
            newPoints.append((transformed[0], transformed[1], transformed[2]))
        }
        result = newPoints
    }
    return result
}

func main() {
    let points: [(Double, Double, Double)] = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    let sequence: [[[Double]]] = [
        [[1, 0, 0], [0, 1, 0], [0, 0, 1]],
        [[0, -1, 0], [1, 0, 0], [0, 0, 1]],
        [[1, 0, 0], [0, 1, 0], [0, 0, -1]]
    ]
    let transformedPoints = applySequenceTransformations(points: points, sequence: sequence)
    for point in transformedPoints {
        print(point)
    }
}

main()