func updateState(_ grid: [[Int]], _ width: Int, _ height: Int) -> [[Int]] {
    var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0
            for dy in -1...1 {
                for dx in -1...1 {
                    if dy == 0 && dx == 0 {
                        continue
                    }
                    let nx = x + dx
                    let ny = y + dy
                    if nx >= 0 && nx < width && ny >= 0 && ny < height {
                        neighbors += grid[ny][nx]
                    }
                }
            }
            if grid[y][x] == 1 {
                newGrid[y][x] = (2...3).contains(neighbors) ? 1 : 0
            } else {
                newGrid[y][x] = neighbors == 3 ? 1 : 0
            }
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]], _ width: Int, _ height: Int, _ steps: Int) -> [[Int]] {
    if steps == 0 {
        return grid
    } else {
        return simulate(updateState(grid, width, height), width, height, steps - 1)
    }
}

func main() {
    let width = 50
    let height = 50
    let steps = 100
    let grid = (0..<height).map { y in
        (0..<width).map { x in
            (x + y) % 2 == 0 ? 1 : 0
        }
    }
    let finalGrid = simulate(grid, width, height, steps)
    for row in finalGrid {
        let rowString = row.map { $0 == 1 ? "O" : " " }.joined()
        print(rowString)
    }
}

main()