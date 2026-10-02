func updateState(_ grid: [[Int]]) -> [[Int]] {
    let rowCount = grid.count
    let colCount = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: colCount), count: rowCount)
    for i in 0..<rowCount {
        for j in 0..<colCount {
            let neighbors = [
                (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)
            ].compactMap { x, y in
                (0..<rowCount).contains(x) && (0..<colCount).contains(y) ? grid[x][y] : nil
            }.reduce(0, +)
            newGrid[i][j] = neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]]) {
    while true {
        let newGrid = updateState(grid)
        for row in newGrid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print()
    }
}

func main() {
    let initialGrid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ]
    simulate(initialGrid)
}

main()