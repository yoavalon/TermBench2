class FluidCell {
    var x: Int
    var y: Int
    var pressure: Double
    var velocity: (Double, Double)

    init(x: Int, y: Int) {
        self.x = x
        self.y = y
        self.pressure = 0.0
        self.velocity = (0.0, 0.0)
    }

    func updatePressure(neighbors: [FluidCell]) {
        var totalPressure = 0.0
        for cell in neighbors {
            totalPressure += cell.pressure
        }
        self.pressure = totalPressure / Double(neighbors.count)
    }

    func updateVelocity(neighbors: [FluidCell]) {
        var dx = 0.0
        var dy = 0.0
        for cell in neighbors {
            dx += cell.velocity.0
            dy += cell.velocity.1
        }
        self.velocity = (dx / Double(neighbors.count), dy / Double(neighbors.count))
    }
}

func getNeighbors(grid: [[FluidCell]], x: Int, y: Int) -> [FluidCell] {
    var neighbors: [FluidCell] = []
    let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for (dx, dy) in directions {
        let nx = x + dx
        let ny = y + dy
        if nx >= 0 && nx < grid.count && ny >= 0 && ny < grid[0].count {
            neighbors.append(grid[nx][ny])
        }
    }
    return neighbors
}

func simulate(grid: [[FluidCell]]) {
    while true {
        for row in grid {
            for cell in row {
                let neighbors = getNeighbors(grid: grid, x: cell.x, y: cell.y)
                cell.updatePressure(neighbors: neighbors)
                cell.updateVelocity(neighbors: neighbors)
            }
        }
    }
}

func main() {
    let width = 10
    let height = 10
    let grid = (0..<width).map { x in
        (0..<height).map { y in
            FluidCell(x: x, y: y)
        }
    }
    simulate(grid: grid)
}

main()