class FluidCell {
    var state: Int

    init(state: Int = 0) {
        self.state = state
    }

    func updateState(neighbors: [FluidCell]) {
        let count = neighbors.filter { $0.state == 1 }.count
        if count == 3 {
            self.state = 1
        } else if count < 2 || count > 3 {
            self.state = 0
        }
    }
}

class Grid {
    var size: Int
    var grid: [[FluidCell]]

    init(size: Int, initialState: [[Int]]? = nil) {
        self.size = size
        if let initialState = initialState {
            self.grid = initialState.map { $0.map { FluidCell(state: $0) } }
        } else {
            self.grid = Array(repeating: Array(repeating: FluidCell(), count: size), count: size)
        }
    }

    func getNeighbors(x: Int, y: Int) -> [FluidCell] {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        var neighbors: [FluidCell] = []
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
        var newGrid: [[Int]] = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = getNeighbors(x: i, y: j)
                grid[i][j].updateState(neighbors: neighbors)
                newGrid[i][j] = grid[i][j].state
            }
        }
        grid = newGrid.map { $0.map { FluidCell(state: $0) } }
    }
}

func main() {
    let size = 10
    let initialState: [[Int]] = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]
    let grid = Grid(size: size, initialState: initialState)
    while true {
        grid.updateGrid()
    }
}

main()