class Cell {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func update(neighbors: [Cell]) {
        let aliveNeighbors = neighbors.filter { $0.state == 1 }.count
        if self.state == 1 {
            if aliveNeighbors < 2 || aliveNeighbors > 3 {
                self.state = 0
            }
        } else if aliveNeighbors == 3 {
            self.state = 1
        }
    }
}

class Grid {
    let width: Int
    let height: Int
    var grid: [[Cell]]

    init(width: Int, height: Int, initialState: [[Int]]) {
        self.width = width
        self.height = height
        self.grid = (0..<width).map { x in
            (0..<height).map { y in
                Cell(state: initialState[x][y])
            }
        }
    }

    func getNeighbors(x: Int, y: Int) -> [Cell] {
        var neighbors: [Cell] = []
        for dx in [-1, 0, 1] {
            for dy in [-1, 0, 1] {
                if dx == 0 && dy == 0 {
                    continue
                }
                let nx = x + dx
                let ny = y + dy
                if nx >= 0 && nx < width && ny >= 0 && ny < height {
                    neighbors.append(grid[nx][ny])
                }
            }
        }
        return neighbors
    }

    func update() {
        let newGrid = (0..<width).map { x in
            (0..<height).map { y in
                Cell(state: 0)
            }
        }
        for x in 0..<width {
            for y in 0..<height {
                let cell = grid[x][y]
                let neighbors = getNeighbors(x: x, y: y)
                newGrid[x][y].update(neighbors: neighbors)
            }
        }
        self.grid = newGrid
    }
}

func main() {
    let width = 10
    let height = 10
    let initialState: [[Int]] = [
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]
    let grid = Grid(width: width, height: height, initialState: initialState)
    while true {
        grid.update()
    }
}

main()