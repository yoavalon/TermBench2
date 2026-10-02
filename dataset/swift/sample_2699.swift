class Automaton {
    var grid: [[Int]]
    var size: Int

    init(gridSize: Int) {
        self.size = gridSize
        self.grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    }

    func update() {
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
        for i in max(0, x - 1)...min(size - 1, x + 1) {
            for j in max(0, y - 1)...min(size - 1, y + 1) {
                if (i, j) != (x, y) && grid[i][j] == 1 {
                    count += 1
                }
            }
        }
        return count
    }
}

func simulate(automaton: Automaton, steps: Int) {
    for _ in 0..<steps {
        automaton.update()
    }
}

func main() {
    let gridSize = 10
    let steps = 50
    let automaton = Automaton(gridSize: gridSize)
    simulate(automaton: automaton, steps: steps)
}

main()