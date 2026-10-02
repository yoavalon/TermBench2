class FluidCell {
    var state: Double

    init(state: Double) {
        self.state = state
    }

    func update(neighbors: [FluidCell]) {
        let avgState = neighbors.map { $0.state }.reduce(0, +) / Double(neighbors.count)
        self.state = avgState
    }
}

class Grid {
    var size: Int
    var cells: [[FluidCell]]

    init(size: Int, initialState: Double) {
        self.size = size
        self.cells = (0..<size).map { _ in
            (0..<size).map { _ in FluidCell(state: initialState) }
        }
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

    func update() {
        var newCells = (0..<size).map { _ in
            (0..<size).map { _ in FluidCell(state: self.cells[$0][$1].state) }
        }
        for x in 0..<size {
            for y in 0..<size {
                let neighbors = getNeighbors(x: x, y: y)
                newCells[x][y].update(neighbors: neighbors)
            }
        }
        self.cells = newCells
    }
}

func main() {
    let gridSize = 10
    let initialState = 0.5
    var grid = Grid(size: gridSize, initialState: initialState)
    while true {
        grid.update()
    }
}

main()