class Cell {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func update(neighbors: [Cell]) {
        let liveNeighbors = neighbors.filter { $0.state == 1 }.count
        if self.state == 1 && (liveNeighbors < 2 || liveNeighbors > 3) {
            self.state = 0
        } else if self.state == 0 && liveNeighbors == 3 {
            self.state = 1
        }
    }
}

class Grid {
    let size: Int
    var cells: [[Cell]]

    init(size: Int, initial_state: [[Int]]) {
        self.size = size
        self.cells = (0..<size).map { i in
            (0..<size).map { j in
                Cell(state: initial_state[i][j])
            }
        }
    }

    func getNeighbors(x: Int, y: Int) -> [Cell] {
        var neighbors: [Cell] = []
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let nx = x + i
                let ny = y + j
                if nx >= 0 && nx < size && ny >= 0 && ny < size {
                    neighbors.append(cells[nx][ny])
                } else {
                    neighbors.append(Cell(state: 0))
                }
            }
        }
        return neighbors
    }

    func update() {
        let newCells = (0..<size).map { i in
            (0..<size).map { j in
                Cell(state: cells[i][j].state)
            }
        }
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = getNeighbors(x: i, y: j)
                newCells[i][j].update(neighbors: neighbors)
            }
        }
        self.cells = newCells
    }
}

func main() {
    let size = 10
    var initialState: [[Int]] = Array(repeating: Array(repeating: 0, count: size), count: size)
    initialState[4][4] = 1
    initialState[4][5] = 1
    initialState[5][4] = 1
    initialState[5][5] = 1
    let grid = Grid(size: size, initial_state: initialState)
    while true {
        grid.update()
    }
}

main()