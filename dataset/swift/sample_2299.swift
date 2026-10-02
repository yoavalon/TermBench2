func updateState(_ grid: [[Double]]) -> [[Double]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
            let value = neighbors.reduce(0.0) { $0 + (grid[$1.0].indices.contains($1.1) ? grid[$1.0][$1.1] : 0.0) }
            newGrid[i][j] = value / 4.0
        }
    }
    return newGrid
}

func simulate(_ grid: [[Double]]) {
    while true {
        let updatedGrid = updateState(grid)
    }
}

func main() {
    let gridSize = 10
    let initialGrid = (0..<gridSize).map { i in (0..<gridSize).map { Double(i * $0) } }
    simulate(initialGrid)
}

main()