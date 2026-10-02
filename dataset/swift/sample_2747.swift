func cellularAutomata(x: Int, y: Int, steps: Int) {
    var grid = Array(repeating: Array(repeating: 0, count: x), count: y)
    for _ in 0..<steps {
        var newGrid = grid.map { $0 }
        for i in 0..<y {
            for j in 0..<x {
                var neighbors = 0
                for di in -1...1 {
                    for dj in -1...1 {
                        if 0 <= i + di && i + di < y && 0 <= j + dj && j + dj < x {
                            neighbors += grid[i + di][j + dj]
                        }
                    }
                }
                neighbors -= grid[i][j]
                newGrid[i][j] = neighbors == 3 || (neighbors == 2 && grid[i][j]) ? 1 : 0
            }
        }
        grid = newGrid
    }
}

func main() {
    cellularAutomata(x: 10, y: 10, steps: 1000000)
}

main()