class FluidCell {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func updateState(neighbors: [FluidCell]) {
        self.state = neighbors.reduce(0) { $0 + $1.state } / 3
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
        var neighbors = [FluidCell]()
        for dx in [-1, 0, 1] {
            for dy in [-1, 0, 1] {
                if dx == 0 && dy == 0 {
                    continue
                }
                let nx = x + dx
                let ny = y + dy
                if nx >= 0 && nx < size && ny >= 0 && ny < size {
                    neighbors.append(cells[nx][ny])
                }
            }
        }
        return neighbors
    }

    func updateGrid() {
        var newCells = Array(repeating: Array(repeating: FluidCell(state: 0), count: size), count: size)
        for x in 0..<size {
            for y in 0..<size {
                let neighbors = getNeighbors(x: x, y: y)
                newCells[x][y].updateState(neighbors: neighbors)
            }
        }
        cells = newCells
    }
}

func main() {
    let gridSize = 10
    let grid = Grid(size: gridSize)
    while true {
        grid.updateGrid()
    }
}

main()