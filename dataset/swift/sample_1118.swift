class Grid {
    var size: Int
    var grid: [[Int]]

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var new_grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 0 {
                    new_grid[i][j] = neighbors == 3 ? 1 : 0
                } else {
                    new_grid[i][j] = neighbors == 2 || neighbors == 3 ? 1 : 0
                }
            }
        }
        grid = new_grid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let ni = x + i
                let nj = y + j
                if ni >= 0 && ni < size && nj >= 0 && nj < size {
                    count += grid[ni][nj]
                }
            }
        }
        return count
    }
}

func display(grid: Grid) {
    for row in grid.grid {
        print(row.map { String($0) }.joined(separator: " "))
    }
    print()
}

func main() {
    let size = 10
    let grid = Grid(size: size)
    while true {
        display(grid: grid)
        grid.update()
    }
}

main()