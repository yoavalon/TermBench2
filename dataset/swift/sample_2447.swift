func transformCoordinates(points: [(Double, Double, Double)], matrix: [[Double]]) -> [(Double, Double, Double)] {
    var transformed = [(Double, Double, Double)]()
    for point in points {
        let (x, y, z) = point
        let tx = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        let ty = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        let tz = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        transformed.append((tx, ty, tz))
    }
    return transformed
}

let transformationMatrix = [[1.0, 0.0, 0.0, 0.0], [0.0, 1.0, 0.0, 0.0], [0.0, 0.0, 1.0, 0.0], [0.0, 0.0, 0.0, 1.0]]
let pointsList = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)]
let result = transformCoordinates(points: pointsList, matrix: transformationMatrix)
print(result)