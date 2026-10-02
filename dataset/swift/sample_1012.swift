func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
            var liveNeighbors = 0
            
            for (dx, dy) in neighbors {
                let x = i + dx
                let y = j + dy
                if x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 {
                    liveNeighbors += 1
                }
            }
            
            if grid[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3) {
                newGrid[i][j] = 1
            } else if grid[i][j] == 0 && liveNeighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]]) {
    display(grid)
    simulate(updateGrid(grid))
}

func display(_ grid: [[Int]]) {
    for row in grid {
        let line = row.map { $0 == 1 ? "█" : " " }.joined()
        print(line)
    }
}

func main() {
    let initialGrid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 1, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ]
    simulate(initialGrid)
}

main()