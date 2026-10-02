func transformCoordinates(points: [(Double, Double, Double)], matrix: [[Double]]) -> [(Double, Double, Double)] {
    var transformed = [(Double, Double, Double)]()
    for point in points {
        let x = point.0
        let y = point.1
        let z = point.2
        let x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        let y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        let z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        transformed.append((x_new, y_new, z_new))
    }
    return transformed
}

func applyTransformation() -> [(Double, Double, Double)] {
    let points = [(1.0, 2.0, 3.0), (4.0, 5.0, 6.0)]
    let matrix = [[1.0, 0.0, 0.0, 1.0], [0.0, 1.0, 0.0, 2.0], [0.0, 0.0, 1.0, 3.0]]
    return transformCoordinates(points: points, matrix: matrix)
}

let result = applyTransformation()
print(result)