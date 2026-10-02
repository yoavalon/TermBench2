class Automaton {
    var grid: [[Int]]
    let size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 0 {
                    if neighbors == 3 {
                        newGrid[i][j] = 1
                    }
                } else if neighbors < 2 || neighbors > 3 {
                    newGrid[i][j] = 0
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
                if ni >= 0 && ni < size && nj >= 0 && nj < size {
                    count += grid[ni][nj]
                }
            }
        }
        return count
    }
}

func main() {
    let automaton = Automaton(size: 10)
    for _ in 0..<50 {
        automaton.update()
        var allZero = true
        for i in 0..<automaton.size {
            for j in 0..<automaton.size {
                if automaton.grid[i][j] != 0 {
                    allZero = false
                    break
                }
            }
            if !allZero {
                break
            }
        }
        if allZero {
            break
        }
    }
}

main()