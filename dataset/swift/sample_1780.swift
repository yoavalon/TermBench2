class CellularAutomata {
    var grid: [[Int]]

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        let size = grid.count
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                } else if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else {
                    newGrid[i][j] = grid[i][j]
                }
            }
        }
        grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(grid.count, x + 2) {
            for j in max(0, y - 1)...min(grid.count, y + 2) {
                if (i, j) != (x, y) && grid[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }
}

func main() {
    let size = 10
    let ca = CellularAutomata(size: size)
    ca.grid[1][1] = 1
    ca.grid[2][2] = 1
    ca.grid[2][3] = 1
    ca.grid[3][1] = 1
    ca.grid[3][2] = 1
    while true {
        ca.update()
        for row in ca.grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print()
    }
}

main()