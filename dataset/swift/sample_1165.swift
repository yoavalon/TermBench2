class FluidGrid {
    var grid: [[Int]]
    var size: Int

    init(size: Int) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                newGrid[i][j] = calculateNextState(x: i, y: j)
            }
        }
        self.grid = newGrid
    }

    func calculateNextState(x: Int, y: Int) -> Int {
        let neighbors = getNeighbors(x: x, y: y)
        let count = neighbors.reduce(0, +)
        if grid[x][y] == 0 {
            return count > 2 ? 1 : 0
        } else {
            return count == 2 || count == 3 ? 1 : 0
        }
    }

    func getNeighbors(x: Int, y: Int) -> [Int] {
        let directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        var neighbors = [Int]()
        for (dx, dy) in directions {
            let nx = x + dx
            let ny = y + dy
            if nx >= 0 && nx < size && ny >= 0 && ny < size {
                neighbors.append(grid[nx][ny])
            } else {
                neighbors.append(0)
            }
        }
        return neighbors
    }
}

func main() {
    let size = 10
    let grid = FluidGrid(size: size)
    while true {
        grid.update()
    }
}

main()