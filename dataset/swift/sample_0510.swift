class FluidCell {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func updateState(neighbors: [FluidCell]) {
        let activeNeighbors = neighbors.filter { $0.state == 1 }.count
        if activeNeighbors == 2 || activeNeighbors == 3 {
            self.state = 1
        } else {
            self.state = 0
        }
    }
}

class Grid {
    var size: Int
    var grid: [[FluidCell]]

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: FluidCell(state: 0), count: size), count: size)
    }

    func getNeighbors(x: Int, y: Int) -> [FluidCell] {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        var neighbors = [FluidCell]()
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if nx >= 0 && nx < size && ny >= 0 && ny < size {
                neighbors.append(grid[nx][ny])
            }
        }
        return neighbors
    }

    func updateGrid() {
        var newGrid = Array(repeating: Array(repeating: FluidCell(state: 0), count: size), count: size)
        for x in 0..<size {
            for y in 0..<size {
                let neighbors = getNeighbors(x: x, y: y)
                newGrid[x][y].updateState(neighbors: neighbors)
            }
        }
        grid = newGrid
    }
}

func main() {
    let gridSize = 50
    let simulation = Grid(size: gridSize)
    while true {
        simulation.updateGrid()
    }
}

main()