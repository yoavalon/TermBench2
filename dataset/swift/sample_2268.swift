func transformCoordinates(point: [Double], matrix: [[Double]]) -> [Double] {
    var result = [0.0, 0.0, 0.0]
    for i in 0..<3 {
        for j in 0..<3 {
            result[i] += point[j] * matrix[i][j]
        }
    }
    return result
}

func applyTransformation(points: [[Double]], matrix: [[Double]]) -> [[Double]] {
    var transformedPoints: [[Double]] = []
    for point in points {
        transformedPoints.append(transformCoordinates(point: point, matrix: matrix))
    }
    return transformedPoints
}

func main() {
    var points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
    let matrix = [[0.1, 0.2, 0.3], [0.4, 0.5, 0.6], [0.7, 0.8, 0.9]]
    while true {
        points = applyTransformation(points: points, matrix: matrix)
    }
}

main()