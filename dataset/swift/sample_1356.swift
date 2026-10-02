func transformCoordinates(coords: [(Int, Int, Int)], matrix: [[Int]]) -> [(Int, Int, Int)] {
    var result: [(Int, Int, Int)] = []
    for coord in coords {
        let x = coord.0
        let y = coord.1
        let z = coord.2
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        result.append((new_x, new_y, new_z))
    }
    return result
}

func applyTransformation(coords: [(Int, Int, Int)], matrix: [[Int]]) -> [(Int, Int, Int)] {
    return transformCoordinates(coords: coords, matrix: matrix)
}

func main() {
    let coords = [(1, 2, 3), (4, 5, 6)]
    let matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]]
    let transformed = applyTransformation(coords: coords, matrix: matrix)
    print(transformed)
}

main()