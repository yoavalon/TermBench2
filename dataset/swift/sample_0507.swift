swift
import Foundation

class Grid {
    var size: Int
    var grid: [[Int]]

    init(size: Int) {
        self.size = size
        self.grid = (0..<size).map { _ in (0..<size).map { _ in Int.random(in: 0...1) } }
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let state = grid[i][j]
                let neighbors = countNeighbors(x: i, y: j)
                if state == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                } else if state == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else {
                    newGrid[i][j] = state
                }
            }
        }
        grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in max(0, x - 1)...min(x + 1, size - 1) {
            for j in max(0, y - 1)...min(y + 1, size - 1) {
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

    init(grid: Grid) {
        self.grid = grid
    }

    func run() {
        while true {
            grid.update()
            display()
        }
    }

    func display() {
        for row in grid.grid {
            print(row.map { $0 == 1 ? "#" : " " }.joined())
        }
        print(String(repeating: "-", count: grid.size))
    }
}

func main() {
    let size = 50
    let grid = Grid(size: size)
    let simulation = Simulation(grid: grid)
    simulation.run()
}

main()