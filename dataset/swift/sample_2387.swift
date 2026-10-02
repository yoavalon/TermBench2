swift
class FluidCell {
    var state: Double

    init(state: Double) {
        self.state = state
    }

    func updateState(neighbors: [FluidCell]) {
        self.state = neighbors.reduce(0) { $0 + $1.state } / Double(neighbors.count)
    }
}

class FluidGrid {
    var size: Int
    var grid: [[FluidCell]]

    init(size: Int, initialState: Double) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: FluidCell(state: initialState), count: size), count: size)
    }

    func getNeighbors(x: Int, y: Int) -> [FluidCell] {
        var neighbors = [FluidCell]()
        for dx in -1...1 {
            for dy in -1...1 {
                let nx = x + dx
                let ny = y + dy
                if nx >= 0 && nx < size && ny >= 0 && ny < size && (dx != 0 || dy != 0) {
                    neighbors.append(grid[nx][ny])
                }
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
    let size = 10
    let initialState = 1.0
    var grid = FluidGrid(size: size, initialState: initialState)
    while true {
        grid.updateGrid()
    }
}

main()