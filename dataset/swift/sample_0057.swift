func transformCoordinates(coords: [[Int]], matrix: [[Int]]) -> [[Int]] {
    return coords.map { row in
        matrix.map { col in
            zip(row, col).map { $0 * $1 }.reduce(0, +)
        }
    }
}

func main() {
    let coords = [[1, 2, 3], [4, 5, 6]]
    let matrix = [[0, 1, 0], [-1, 0, 0], [0, 0, 1]]
    let result = transformCoordinates(coords: coords, matrix: matrix)
    print(result)
}

main()