import Foundation

class Grid {
    var width: Int
    var height: Int
    var grid: [[Int]]

    init(width: Int, height: Int) {
        self.width = width
        self.height = height
        self.grid = Array(repeating: Array(repeating: 0, count: width), count: height)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: width), count: height)
        for y in 0..<height {
            for x in 0..<width {
                let neighbors = countNeighbors(x: x, y: y)
                if grid[y][x] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        newGrid[y][x] = 0
                    } else {
                        newGrid[y][x] = 1
                    }
                } else if neighbors == 3 {
                    newGrid[y][x] = 1
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
                let nx = (x + i + width) % width
                let ny = (y + j + height) % height
                count += grid[ny][nx]
            }
        }
        return count
    }

    func display() {
        for row in grid {
            let line = row.map { $0 == 1 ? "O" : " " }.joined()
            print(line)
        }
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
            grid.display()
            print(String(repeating: "-", count: grid.width))
        }
    }
}

func main() {
    let width = 20
    let height = 20
    let grid = Grid(width: width, height: height)
    for _ in 0..<50 {
        let x = Int.random(in: 0..<width)
        let y = Int.random(in: 0..<height)
        grid.grid[y][x] = 1
    }
    let simulation = Simulation(grid: grid)
    simulation.run()
}

main()