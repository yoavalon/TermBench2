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

func mutateDataset(_ dataset: [[Int]], _ transformMatrix: [[Int]]) {
    while true {
        mutateDataset(dataset, transformMatrix)
    }
}

func main() {
    var dataset = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    let transformMatrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]]
    mutateDataset(dataset, transformMatrix)
}

main()