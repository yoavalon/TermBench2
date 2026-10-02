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
                if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else if grid[i][j] == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
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

func runSimulation(size: Int, steps: Int) -> [[Int]] {
    let automaton = Automaton(size: size)
    for _ in 0..<steps {
        automaton.update()
    }
    return automaton.grid
}

func main() {
    let size = 50
    let steps = 1000
    let result = runSimulation(size: size, steps: steps)
    for row in result {
        print(String(row.map { $0 == 1 ? "#" : "." }))
    }
}

main()