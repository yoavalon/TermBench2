import Foundation

class Grid {
    var grid: [[Int]]
    let size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var newGrid = grid.map { $0 }
        for i in 1..<size - 1 {
            for j in 1..<size - 1 {
                let neighbors = getNeighbors(at: (i, j))
                newGrid[i][j] = rules(neighbors: neighbors)
            }
        }
        grid = newGrid
    }

    func rules(neighbors: [Int]) -> Int {
        let count = neighbors.reduce(0, +) - grid[1][1]
        if grid[1][1] == 1 && (count < 2 || count > 3) {
            return 0
        } else if grid[1][1] == 0 && count == 3 {
            return 1
        }
        return grid[1][1]
    }

    func getNeighbors(at position: (Int, Int)) -> [Int] {
        let (i, j) = position
        var neighbors: [Int] = []
        for x in i - 1...i + 1 {
            for y in j - 1...j + 1 {
                neighbors.append(grid[x][y])
            }
        }
        return neighbors
    }
}

class BoundaryHandler {
    func apply(to grid: inout Grid) {
        grid.grid[0] = grid.grid[size - 2]
        grid.grid[size - 1] = grid.grid[1]
        for i in 0..<size {
            grid.grid[i][0] = grid.grid[i][size - 2]
            grid.grid[i][size - 1] = grid.grid[i][1]
        }
    }
}

class Simulator {
    var grid: Grid
    var boundaryHandler: BoundaryHandler
    let iterations: Int

    init(grid: Grid, boundaryHandler: BoundaryHandler, iterations: Int) {
        self.grid = grid
        self.boundaryHandler = boundaryHandler
        self.iterations = iterations
    }

    func run() {
        for _ in 0..<iterations {
            grid.update()
            boundaryHandler.apply(to: &grid)
        }
    }
}

func main() {
    let size = 10
    let iterations = 50
    let grid = Grid(size: size)
    let boundaryHandler = BoundaryHandler()
    let simulator = Simulator(grid: grid, boundaryHandler: boundaryHandler, iterations: iterations)
    simulator.run()
    print(grid.grid)
}

main()