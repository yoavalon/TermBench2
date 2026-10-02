class Grid {
    var grid: [[Int]]
    var size: Int

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
        for i in x - 1...x + 1 {
            for j in y - 1...y + 1 {
                if (i != x || j != y) && i >= 0 && i < size && j >= 0 && j < size {
                    count += grid[i][j]
                }
            }
        }
        return count
    }
}

class Simulation {
    var grid: Grid
    var steps: Int

    init(grid: Grid) {
        self.grid = grid
        self.steps = 0
    }

    func run(maxSteps: Int) {
        while steps < maxSteps {
            grid.update()
            steps += 1
        }
    }
}

func main() {
    let size = 50
    let maxSteps = 100
    let grid = Grid(size: size)
    let simulation = Simulation(grid: grid)
    simulation.run(maxSteps: maxSteps)
}

main()