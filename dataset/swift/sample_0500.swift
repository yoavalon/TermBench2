func transformCoordinates(_ coords: [[Int]], _ matrix: [[Int]]) -> [[Int]] {
    var result: [[Int]] = []
    for coord in coords {
        var newCoord = [0, 0, 0]
        for i in 0..<3 {
            for j in 0..<3 {
                newCoord[i] += coord[j] * matrix[i][j]
            }
        }
        result.append(newCoord)
    }
    return result
}

func applyBoundaryConditions(_ coords: [[Int]], _ boundary: [[Int]]) -> [[Int]] {
    let transformed = transformCoordinates(coords, boundary)
    return transformed
}

func main() {
    var coords = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    let boundary = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
    while true {
        coords = applyBoundaryConditions(coords, boundary)
    }
}

main()