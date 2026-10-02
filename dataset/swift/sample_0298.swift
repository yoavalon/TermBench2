import Foundation

class AutomataGrid {
    var grid: [[Int]]
    let size: Int

    init(size: Int, density: Double) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                self.grid[i][j] = Int.random(in: 0...1) == 1 ? 1 : 0
            }
        }
    }

    func applyRules() {
        var newGrid = grid
        for i in 1..<(size - 1) {
            for j in 1..<(size - 1) {
                let neighbors = (grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] +
                                grid[i][j-1] + grid[i][j+1] +
                                grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1])
                if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else if grid[i][j] == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        self.grid = newGrid
    }

    func setBoundaryConditions() {
        for i in 0..<size {
            grid[i][0] = grid[i][size - 2]
            grid[i][size - 1] = grid[i][1]
            grid[0][i] = grid[size - 2][i]
            grid[size - 1][i] = grid[1][i]
        }
    }
}

class Simulation {
    var grid: AutomataGrid
    let steps: Int

    init(grid: AutomataGrid, steps: Int) {
        self.grid = grid
        self.steps = steps
    }

    func run() {
        for _ in 0..<steps {
            grid.applyRules()
            grid.setBoundaryConditions()
        }
    }
}

func main() {
    let size = 10
    let density = 0.3
    let steps = 50
    let grid = AutomataGrid(size: size, density: density)
    let simulation = Simulation(grid: grid, steps: steps)
    simulation.run()
}

main()