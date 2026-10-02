func cellularAutomata(n: Int, m: Int) {
    var grid = Array(repeating: Array(repeating: 0, count: m), count: n)
    while true {
        var newGrid = Array(repeating: Array(repeating: 0, count: m), count: n)
        for i in 0..<n {
            for j in 0..<m {
                let state = grid[i][j]
                var neighbors = 0
                for x in i - 1...i + 1 {
                    for y in j - 1...j + 1 {
                        if x >= 0 && x < n && y >= 0 && y < m {
                            neighbors += grid[x][y]
                        }
                    }
                }
                neighbors -= state
                newGrid[i][j] = neighbors == 3 || (state == 1 && neighbors == 2) ? 1 : 0
            }
        }
        grid = newGrid
    }
}

func main() {
    cellularAutomata(n: 10, m: 10)
}

main()