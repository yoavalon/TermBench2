class CellularAutomaton {
    var gridSize: Int
    var rule: [String: [Int]]
    var grid: [[Int]]

    init(gridSize: Int, rule: [String: [Int]]) {
        self.gridSize = gridSize
        self.rule = rule
        self.grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        self.grid[gridSize / 2][gridSize / 2] = 1
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        for i in 0..<gridSize {
            for j in 0..<gridSize {
                let neighbors = countNeighbors(x: i, y: j)
                newGrid[i][j] = applyRule(cell: grid[i][j], neighbors: neighbors)
            }
        }
        self.grid = newGrid
    }

    func countNeighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in (x - 1)...(x + 1) {
            for j in (y - 1)...(y + 1) {
                if i >= 0 && i < gridSize && j >= 0 && j < gridSize && !(i == x && j == y) {
                    count += grid[i][j]
                }
            }
        }
        return count
    }

    func applyRule(cell: Int, neighbors: Int) -> Int {
        if cell == 1 && rule["survive"]!.contains(neighbors) {
            return 1
        } else if cell == 0 && rule["birth"]!.contains(neighbors) {
            return 1
        }
        return 0
    }
}

func main() {
    let size = 50
    let rule = ["survive": [2, 3], "birth": [3]]
    let ca = CellularAutomaton(gridSize: size, rule: rule)
    for _ in 0..<100 {
        ca.update()
    }
    for row in ca.grid {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()