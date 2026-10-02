class Cell {
    var state: Int

    init(state: Int = 0) {
        self.state = state
    }

    func update(neighbors: [Cell]) {
        let liveNeighbors = neighbors.filter { $0.state == 1 }.count
        if self.state == 1 {
            self.state = (liveNeighbors == 2 || liveNeighbors == 3) ? 1 : 0
        } else {
            self.state = liveNeighbors == 3 ? 1 : 0
        }
    }
}

class Grid {
    var width: Int
    var height: Int
    var grid: [[Cell]]

    init(width: Int, height: Int, initial_state: [[Int]]? = nil) {
        self.width = width
        self.height = height
        self.grid = (0..<height).map { i in
            (0..<width).map { j in
                initial_state != nil ? Cell(state: initial_state![i][j]) : Cell()
            }
        }
    }

    func getNeighbors(x: Int, y: Int) -> [Cell] {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        var neighbors: [Cell] = []
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if nx >= 0 && nx < width && ny >= 0 && ny < height {
                neighbors.append(grid[ny][nx])
            }
        }
        return neighbors
    }

    func update() {
        var newGrid = (0..<height).map { i in
            (0..<width).map { j in
                Cell(state: self.grid[i][j].state)
            }
        }
        for i in 0..<height {
            for j in 0..<width {
                let neighbors = getNeighbors(x: j, y: i)
                newGrid[i][j].update(neighbors: neighbors)
            }
        }
        self.grid = newGrid
    }
}

func main() {
    let initialState = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    let grid = Grid(width: 3, height: 3, initial_state: initialState)
    while true {
        grid.update()
    }
}

main()