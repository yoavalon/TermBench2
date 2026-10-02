import Foundation

class Automaton {
    var grid: [[Int]]
    let size: Int

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        self.size = size
    }

    func update() {
        var newGrid = grid
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = grid[(i - 1 + size) % size][(j - 1 + size) % size] + grid[(i - 1 + size) % size][j] + grid[(i - 1 + size) % size][(j + 1) % size] + grid[i][(j - 1 + size) % size] + grid[i][(j + 1) % size] + grid[(i + 1) % size][(j - 1 + size) % size] + grid[(i + 1) % size][j] + grid[(i + 1) % size][(j + 1) % size]
                if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else if grid[i][j] == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        grid = newGrid
    }
}

class BoundaryHandler {
    let automaton: Automaton

    init(automaton: Automaton) {
        self.automaton = automaton
    }

    func applyBoundaryConditions() {
        automaton.grid[0] = Array(repeating: 0, count: automaton.size)
        automaton.grid[automaton.size - 1] = Array(repeating: 0, count: automaton.size)
        for i in 0..<automaton.size {
            automaton.grid[i][0] = 0
            automaton.grid[i][automaton.size - 1] = 0
        }
    }
}

func main() {
    let size = 100
    let automaton = Automaton(size: size)
    let boundaryHandler = BoundaryHandler(automaton: automaton)
    automaton.grid[1][2] = 1
    automaton.grid[2][3] = 1
    automaton.grid[3][1] = 1
    automaton.grid[3][2] = 1
    automaton.grid[3][3] = 1
    while true {
        boundaryHandler.applyBoundaryConditions()
        automaton.update()
    }
}

main()