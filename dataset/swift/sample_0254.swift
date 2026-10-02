class FluidCell {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func update(neighbors: [FluidCell]) {
        self.state = neighbors.reduce(0) { $0 + $1.state } / neighbors.count
    }
}

class Grid {
    var size: Int
    var cells: [[FluidCell]]

    init(size: Int) {
        self.size = size
        self.cells = Array(repeating: Array(repeating: FluidCell(state: 0), count: size), count: size)
    }

    func getNeighbors(x: Int, y: Int) -> [FluidCell] {
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        var neighbors: [FluidCell] = []
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if 0 <= nx && nx < size && 0 <= ny && ny < size {
                neighbors.append(cells[nx][ny])
            }
        }
        return neighbors
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: FluidCell(state: 0), count: size), count: size)
        for x in 0..<size {
            for y in 0..<size {
                let neighbors = getNeighbors(x: x, y: y)
                newGrid[x][y].update(neighbors: neighbors)
            }
        }
        self.cells = newGrid
    }
}

class Simulation {
    var grid: Grid
    var steps: Int

    init(gridSize: Int, steps: Int) {
        self.grid = Grid(size: gridSize)
        self.steps = steps
    }

    func run() {
        for _ in 0..<steps {
            grid.update()
        }
    }
}

func main() {
    let simulation = Simulation(gridSize: 10, steps: 50)
    simulation.run()
}

main()