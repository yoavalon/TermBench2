import Foundation

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
                let neighbors = getNeighbors(x: i, y: j)
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

    func getNeighbors(x: Int, y: Int) -> Int {
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

class Simulation {
    var grid: Grid

    init(grid: Grid) {
        self.grid = grid
    }

    func run() {
        while true {
            grid.update()
        }
    }
}

func main() {
    let size = 50
    let grid = Grid(size: size)
    let simulation = Simulation(grid: grid)
    simulation.run()
}

main()