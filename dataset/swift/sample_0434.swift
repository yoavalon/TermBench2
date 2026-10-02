func updateCell(state: Int, neighbors: [Int]) -> Int {
    let activeNeighbors = neighbors.reduce(0, +)
    if state == 1 {
        return activeNeighbors == 2 || activeNeighbors == 3 ? 1 : 0
    } else {
        return activeNeighbors == 3 ? 1 : 0
    }
}

func simulate(grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = [Int]()
            for x in [-1, 0, 1] {
                for y in [-1, 0, 1] {
                    if x == 0 && y == 0 {
                        continue
                    }
                    let ni = i + x
                    let nj = j + y
                    if ni >= 0 && ni < rows && nj >= 0 && nj < cols {
                        neighbors.append(grid[ni][nj])
                    }
                }
            }
            newGrid[i][j] = updateCell(state: grid[i][j], neighbors: neighbors)
        }
    }
    return newGrid
}

func main() {
    var grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    while true {
        grid = simulate(grid: grid)
    }
}

main()