class FluidCell {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func updateState(neighbors: [FluidCell]) {
        let activeNeighbors = neighbors.filter { $0.state > 0 }.count
        if activeNeighbors > 4 {
            self.state = 2
        } else if activeNeighbors < 2 {
            self.state = 0
        } else {
            self.state = 1
        }
    }
}

class FluidGrid {
    var grid: [[FluidCell]]
    let size: Int

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: FluidCell(state: 0), count: size), count: size)
        self.size = size
    }

    func getNeighbors(x: Int, y: Int) -> [FluidCell] {
        var neighbors: [FluidCell] = []
        for i in (x - 1)...(x + 1) {
            for j in (y - 1)...(y + 1) {
                if (0...size-1).contains(i) && (0...size-1).contains(j) && (i != x || j != y) {
                    neighbors.append(grid[i][j])
                }
            }
        }
        return neighbors
    }

    func updateGrid() {
        var newGrid = Array(repeating: Array(repeating: FluidCell(state: 0), count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = getNeighbors(x: i, y: j)
                newGrid[i][j].updateState(neighbors: neighbors)
            }
        }
        self.grid = newGrid
    }
}

func main() {
    let size = 10
    let grid = FluidGrid(size: size)
    while true {
        grid.updateGrid()
    }
}

main()