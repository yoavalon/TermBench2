swift
class FluidCell {
    var value: Double

    init(value: Double) {
        self.value = value
    }

    func update(neighbors: [FluidCell]) {
        self.value = neighbors.map { $0.value }.reduce(0.0, +) / Double(neighbors.count)
    }
}

class FluidGrid {
    var grid: [[FluidCell]]

    init(size: Int) {
        self.grid = Array(repeating: Array(repeating: FluidCell(value: 0.0), count: size), count: size)
    }

    func getNeighbors(x: Int, y: Int) -> [FluidCell] {
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        var neighbors = [FluidCell]()
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if nx >= 0 && nx < grid.count && ny >= 0 && ny < grid.count {
                neighbors.append(grid[nx][ny])
            }
        }
        return neighbors
    }

    func updateCells() {
        let size = grid.count
        var newGrid = Array(repeating: Array(repeating: FluidCell(value: 0.0), count: size), count: size)
        for x in 0..<size {
            for y in 0..<size {
                let neighbors = getNeighbors(x: x, y: y)
                newGrid[x][y].update(neighbors: neighbors)
            }
        }
        grid = newGrid
    }
}

func main() {
    let size = 100
    var fluidGrid = FluidGrid(size: size)
    for cell in fluidGrid.grid[0] {
        cell.value = 1.0
    }
    while true {
        fluidGrid.updateCells()
    }
}

main()