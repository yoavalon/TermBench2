func updateGrid(grid: [[Int]], rules: [([Int]): Int]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors: [Int] = []
            for x in max(0, i - 1)...min(rows - 1, i + 1) {
                for y in max(0, j - 1)...min(cols - 1, j + 1) {
                    if (x, y) != (i, j) {
                        neighbors.append(grid[x][y])
                    }
                }
            }
            newGrid[i][j] = rules[neighbors.sorted()] ?? 0
        }
    }
    return newGrid
}

func main() {
    var grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]]
    let rules: [([Int]): Int] = [
        ([0, 0, 0, 0, 0, 0, 0, 0]): 0,
        ([1, 1, 1, 1, 1, 1, 1, 1]): 1,
        ([0, 0, 0, 1, 1, 1, 0, 0]): 1
    ]
    while true {
        grid = updateGrid(grid: grid, rules: rules)
    }
}

main()