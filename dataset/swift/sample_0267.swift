class Grid {
    var size: Int
    var grid: [[Int]]
    var boundary: String

    init(size: Int, boundary: String) {
        self.size = size
        self.grid = Array(repeating: Array(repeating: 0, count: size), count: size)
        self.boundary = boundary
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                let neighbors = boundaryCondition(x: i, y: j)
                newGrid[i][j] = applyRules(neighbors: neighbors, current: grid[i][j])
            }
        }
        grid = newGrid
    }

    func boundaryCondition(x: Int, y: Int) -> [Int] {
        var neighbors: [Int] = []
        for dx in [-1, 0, 1] {
            for dy in [-1, 0, 1] {
                if dx == 0 && dy == 0 {
                    continue
                }
                let nx = (x + dx + size) % size
                let ny = (y + dy + size) % size
                if boundary == "fixed" {
                    if nx >= 0 && nx < size && ny >= 0 && ny < size {
                        neighbors.append(grid[nx][ny])
                    }
                } else if boundary == "periodic" {
                    neighbors.append(grid[nx][ny])
                }
            }
        }
        return neighbors
    }

    func applyRules(neighbors: [Int], current: Int) -> Int {
        let count = neighbors.reduce(0, +)
        if current == 1 {
            if count < 2 || count > 3 {
                return 0
            }
            return 1
        } else {
            if count == 3 {
                return 1
            }
            return 0
        }
    }
}

func main() {
    let size = 10
    let boundary = "periodic"
    let grid = Grid(size: size, boundary: boundary)
    let steps = 50
    for _ in 0..<steps {
        grid.update()
    }
}

main()