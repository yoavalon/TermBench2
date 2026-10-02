func transformCoordinates(coords: [(Int, Int, Int)], matrix: [[Int]]) -> [[Int]] {
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

if CommandLine.arguments.count > 1 && CommandLine.arguments[1] == "main" {
    let coords: [(Int, Int, Int)] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    let matrix: [[Int]] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    print(transformCoordinates(coords: coords, matrix: matrix))
}