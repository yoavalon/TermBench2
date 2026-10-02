func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors: [Int] = []
            for di in -1...1 {
                for dj in -1...1 {
                    if i + di >= 0 && i + di < rows && j + dj >= 0 && j + dj < cols {
                        neighbors.append(grid[i + di][j + dj])
                    }
                }
            }
            newGrid[i][j] = neighbors.reduce(0, +) / neighbors.count
        }
    }
    return newGrid
}

func display(_ grid: [[Int]]) {
    for row in grid {
        print(row.map { String($0) }.joined(separator: " "))
    }
    print()
}

func simulate(_ grid: [[Int]]) {
    display(grid)
    simulate(updateGrid(grid))
}

func main() {
    let grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]]
    simulate(grid)
}

main()