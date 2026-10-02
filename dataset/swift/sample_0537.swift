class Grid {
    var grid: [[Int]]
    var size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update(rule: (Int, [Int]) -> Int) {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = getNeighbors(x: i, y: j)
                newGrid[i][j] = rule(grid[i][j], neighbors)
            }
        }
        self.grid = newGrid
    }

    func getNeighbors(x: Int, y: Int) -> [Int] {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        var neighbors = [Int]()
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if nx >= 0 && nx < size && ny >= 0 && ny < size {
                neighbors.append(grid[nx][ny])
            }
        }
        return neighbors
    }
}

class Automaton {
    var grid: Grid

    init(grid: Grid) {
        self.grid = grid
    }

    func run(rule: (Int, [Int]) -> Int, steps: Int) {
        for _ in 0..<steps {
            grid.update(rule: rule)
        }
    }
}

func simpleRule(center: Int, neighbors: [Int]) -> Int {
    let liveNeighbors = neighbors.reduce(0, +)
    if center == 1 {
        return liveNeighbors == 2 || liveNeighbors == 3 ? 1 : 0
    } else {
        return liveNeighbors == 3 ? 1 : 0
    }
}

func main() {
    let gridSize = 10
    var initialGrid = Grid(size: gridSize)
    initialGrid.grid[4][4] = 1
    initialGrid.grid[5][5] = 1
    initialGrid.grid[6][4] = 1
    initialGrid.grid[5][3] = 1
    initialGrid.grid[4][5] = 1
    let automaton = Automaton(grid: initialGrid)
    while true {
        automaton.run(rule: simpleRule, steps: 1)
    }
}

main()