import Foundation

class Grid {
    var size: Int
    var grid: [[Int]]

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 1 {
                    newGrid[i][j] = neighbors == 2 || neighbors == 3 ? 1 : 0
                } else {
                    newGrid[i][j] = neighbors == 3 ? 1 : 0
                }
            }
        }
        self.grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(size - 1, x + 1) {
            for j in max(0, y - 1)...min(size - 1, y + 1) {
                if (i, j) != (x, y) {
                    count += grid[i][j]
                }
            }
        }
        return count
    }
}

class Simulation {
    var grid: Grid

    init(gridSize: Int) {
        self.grid = Grid(size: gridSize)
        self.populateGrid()
    }

    func populateGrid() {
        for i in 0..<grid.size {
            for j in 0..<grid.size {
                grid.grid[i][j] = Int.random(in: 0...1)
            }
        }
    }

    func run() {
        while true {
            grid.update()
        }
    }
}

func main() {
    let sim = Simulation(gridSize: 10)
    sim.run()
}

main()