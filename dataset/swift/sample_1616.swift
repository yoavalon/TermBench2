func transformCoordinates(x: Double, y: Double, z: Double, matrix: [[Double]]) -> [Double] {
    return [matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3], matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3], matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]]
}

func applyTransformation(data: [(Double, Double, Double)], transformationMatrix: [[Double]]) -> [(Double, Double, Double)] {
    var result: [(Double, Double, Double)] = []
    for point in data {
        let transformedPoint = transformCoordinates(x: point.0, y: point.1, z: point.2, matrix: transformationMatrix)
        result.append((transformedPoint[0], transformedPoint[1], transformedPoint[2]))
    }
    return result
}

func main() {
    let data: [(Double, Double, Double)] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    let matrix: [[Double]] = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]]
    while true {
        let transformedData = applyTransformation(data: data, transformationMatrix: matrix)
        let newData = transformedData
    }
}

main()