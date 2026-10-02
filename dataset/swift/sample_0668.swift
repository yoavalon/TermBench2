func cellularAutomata(grid: [[Int]], steps: Int) -> [[Int]] {
    if steps == 0 {
        return grid
    }
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for (dx, dy) in [(-1, 0), (1, 0), (0, -1), (0, 1)] {
                let x = i + dx
                let y = j + dy
                if x >= 0 && x < rows && y >= 0 && y < cols {
                    neighbors += grid[x][y]
                }
            }
            newGrid[i][j] = neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0
        }
    }
    return cellularAutomata(grid: newGrid, steps: steps - 1)
}

let grid = [
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0]
]

let result = cellularAutomata(grid: grid, steps: 10)
for row in result {
    print(row)
}