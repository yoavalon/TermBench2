func updateState(_ grid: [[Int]]) -> [[Int]] {
    var newGrid = grid.map { $0 }
    for y in 0..<grid.count {
        for x in 0..<grid[y].count {
            var neighbors = [Int]()
            for dy in [-1, 0, 1] {
                for dx in [-1, 0, 1] {
                    if dy == 0 && dx == 0 {
                        continue
                    }
                    let ny = y + dy
                    let nx = x + dx
                    if ny >= 0 && ny < grid.count && nx >= 0 && nx < grid[y].count {
                        neighbors.append(grid[ny][nx])
                    }
                }
            }
            let count = neighbors.reduce(0, +)
            if grid[y][x] == 1 && count < 2 {
                newGrid[y][x] = 0
            } else if grid[y][x] == 1 && (count == 2 || count == 3) {
                newGrid[y][x] = 1
            } else if grid[y][x] == 1 && count > 3 {
                newGrid[y][x] = 0
            } else if grid[y][x] == 0 && count == 3 {
                newGrid[y][x] = 1
            }
        }
    }
    return newGrid
}

func displayGrid(_ grid: [[Int]]) {
    for row in grid {
        let line = row.map { $0 == 1 ? "O" : " " }.joined()
        print(line)
    }
    print()
}

func simulate(_ grid: [[Int]]) {
    displayGrid(grid)
    simulate(updateState(grid))
}

func main() {
    let initialGrid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ]
    simulate(initialGrid)
}

main()