func cellularAutomata(grid: [[Int]], x: Int, y: Int) -> Int {
    if x < 0 || x >= grid.count || y < 0 || y >= grid[0].count {
        return 0
    }
    return grid[x][y] + cellularAutomata(grid: grid, x: x + 1, y: y) + cellularAutomata(grid: grid, x: x, y: y + 1)
}

func main() {
    var grid = Array(repeating: Array(repeating: 0, count: 10), count: 10)
    while true {
        for i in 0..<grid.count {
            for j in 0..<grid[0].count {
                grid[i][j] = cellularAutomata(grid: grid, x: i, y: j)
            }
        }
    }
}

main()