class FluidCell {
    var state: Int

    init(state: Int = 0) {
        self.state = state
    }

    func update(neighbors: [FluidCell]) {
        let new_state = neighbors.reduce(0) { $0 + $1.state } / neighbors.count
        self.state = new_state
    }
}

class Grid {
    let width: Int
    let height: Int
    var grid: [[FluidCell]]

    init(width: Int, height: Int, initialState: Int = 0) {
        self.width = width
        self.height = height
        self.grid = Array(repeating: Array(repeating: FluidCell(state: initialState), count: width), count: height)
    }

    func getNeighbors(x: Int, y: Int) -> [FluidCell] {
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        var neighbors: [FluidCell] = []
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if 0 <= nx && nx < width && 0 <= ny && ny < height {
                neighbors.append(grid[ny][nx])
            }
        }
        return neighbors
    }

    func updateCells() {
        for y in 0..<height {
            for x in 0..<width {
                let neighbors = getNeighbors(x: x, y: y)
                grid[y][x].update(neighbors: neighbors)
            }
        }
    }
}

class Simulation {
    let grid: Grid

    init(grid: Grid) {
        self.grid = grid
    }

    func run() {
        while true {
            grid.updateCells()
        }
    }
}

func main() {
    let grid = Grid(width: 10, height: 10, initialState: 50)
    let simulation = Simulation(grid: grid)
    simulation.run()
}

main()