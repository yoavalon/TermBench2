func transformCoordinates(_ points: [(Int, Int, Int)], _ matrix: [[Int]]) -> [(Int, Int, Int)] {
    var transformed = [(Int, Int, Int)]()
    for point in points {
        let (x, y, z) = point
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        transformed.append((new_x, new_y, new_z))
    }
    return transformed
}

let points = [(1, 2, 3), (4, 5, 6)]
let matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]]
let result = transformCoordinates(points, matrix)
print(result)