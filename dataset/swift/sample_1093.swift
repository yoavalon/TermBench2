func update_state(_ grid: [[Int]], _ x: Int, _ y: Int, _ size: Int) -> [[Int]] {
    if x < 0 || x >= size || y < 0 || y >= size {
        return grid
    }
    var neighbors = 0
    for i in -1...1 {
        for j in -1...1 {
            if i == 0 && j == 0 {
                continue
            }
            let nx = x + i
            let ny = y + j
            if nx >= 0 && nx < size && ny >= 0 && ny < size {
                neighbors += grid[nx][ny]
            }
        }
    }
    var newGrid = grid
    if grid[x][y] == 1 {
        if neighbors < 2 || neighbors > 3 {
            newGrid[x][y] = 0
        }
    } else if neighbors == 3 {
        newGrid[x][y] = 1
    }
    if x < size - 1 {
        return update_state(newGrid, x + 1, y, size)
    } else if y < size - 1 {
        return update_state(newGrid, 0, y + 1, size)
    } else {
        return newGrid
    }
}

func main() {
    let size = 10
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    grid[size / 2][size / 2] = 1
    while true {
        grid = update_state(grid, 0, 0, size)
    }
}

main()