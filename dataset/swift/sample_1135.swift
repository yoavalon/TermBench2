class Automaton {
    var grid: [[Int]]

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        let gridSize = grid.count
        var newGrid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        for i in 0..<gridSize {
            for j in 0..<gridSize {
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
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let ni = x + i
                let nj = y + j
                if ni >= 0 && ni < grid.count && nj >= 0 && nj < grid[ni].count {
                    count += grid[ni][nj]
                }
            }
        }
        return count
    }
}

func main() {
    let size = 50
    let automaton = Automaton(size: size)
    automaton.grid[size / 2][size / 2] = 1
    automaton.update()
    while true {
        automaton.update()
    }
}

main()