func update_state(_ grid: [[Double]]) -> [[Double]] {
    let rows = grid.count
    let cols = grid[0].count
    var new_grid = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0.0
            for x in -1...1 {
                for y in -1...1 {
                    if x == 0 && y == 0 {
                        continue
                    }
                    let ni = i + x
                    let nj = j + y
                    if ni >= 0 && ni < rows && nj >= 0 && nj < cols {
                        neighbors += grid[ni][nj]
                    }
                }
            }
            new_grid[i][j] = neighbors / 9.0
        }
    }
    return new_grid
}

func run_simulation(steps: Int, size: Int) -> [[Double]] {
    var grid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Double(i == j ? 1.0 : 0.0)
        }
    }
    for _ in 0..<steps {
        grid = update_state(grid)
    }
    return grid
}

if CommandLine.arguments.count > 0 {
    let result = run_simulation(steps: 10, size: 5)
    for row in result {
        print(row)
    }
}