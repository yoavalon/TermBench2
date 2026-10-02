import Foundation

class Automata {
    var grid: [[Int]]
    var boundaryType: String
    var size: Int

    init(size: Int, boundaryType: String) {
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        self.boundaryType = boundaryType
        self.size = size
    }

    func applyBoundaryConditions() {
        if boundaryType == "fixed" {
            for i in 0..<size {
                grid[i][0] = 1
                grid[i][size - 1] = 1
                grid[0][i] = 1
                grid[size - 1][i] = 1
            }
        } else if boundaryType == "periodic" {
            for i in 0..<size {
                grid[i][0] = grid[i][size - 2]
                grid[i][size - 1] = grid[i][1]
                grid[0][i] = grid[size - 2][i]
                grid[size - 1][i] = grid[1][i]
            }
        }
    }

    func updateGrid() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 1..<size - 1 {
            for j in 1..<size - 1 {
                var neighbors = 0
                for ni in i - 1...i + 1 {
                    for nj in j - 1...j + 1 {
                        neighbors += grid[ni][nj]
                    }
                }
                neighbors -= grid[i][j]
                if grid[i][j] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        newGrid[i][j] = 0
                    }
                } else if neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        grid = newGrid
    }
}

class Simulation {
    var automata: Automata
    var steps: Int

    init(automata: Automata, steps: Int) {
        self.automata = automata
        self.steps = steps
    }

    func run() {
        for _ in 0..<steps {
            automata.applyBoundaryConditions()
            automata.updateGrid()
        }
    }
}

func main() {
    let size = 10
    let boundaryType = "fixed"
    let steps = 50
    let automata = Automata(size: size, boundaryType: boundaryType)
    let simulation = Simulation(automata: automata, steps: steps)
    simulation.run()
}

main()