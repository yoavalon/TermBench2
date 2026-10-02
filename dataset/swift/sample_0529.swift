class Grid {
    var grid: [[Int]]

    init(size: Int) {
        grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        let size = grid.count
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = countNeighbors(x: i, y: j)
                if grid[i][j] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        newGrid[i][j] = 0
                    } else {
                        newGrid[i][j] = 1
                    }
                } else if neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in x - 1...x + 1 {
            for j in y - 1...y + 1 {
                if (i != x || j != y) && i >= 0 && i < grid.count && j >= 0 && j < grid[i].count {
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
        grid = Grid(size: gridSize)
    }

    func run() {
        while true {
            grid.update()
        }
    }
}

func main() {
    let simulation = Simulation(gridSize: 10)
    simulation.run()
}

main()