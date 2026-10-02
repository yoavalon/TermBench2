class Grid {
    var size: Int
    var data: [[Int]]

    init(size: Int) {
        self.size = size
        self.data = Array(repeating: Array(repeating: 0, count: size), count: size)
    }

    func update() {
        var new_data = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                new_data[i][j] = self._calculate_next_state(i: i, j: j)
            }
        }
        self.data = new_data
    }

    private func _calculate_next_state(i: Int, j: Int) -> Int {
        let neighbors = self._get_neighbors(i: i, j: j)
        let alive_count = neighbors.reduce(0, +)
        if self.data[i][j] == 1 {
            return alive_count == 2 || alive_count == 3 ? 1 : 0
        } else {
            return alive_count == 3 ? 1 : 0
        }
    }

    private func _get_neighbors(i: Int, j: Int) -> [Int] {
        var neighbors: [Int] = []
        for x in max(0, i - 1)...min(size - 1, i + 1) {
            for y in max(0, j - 1)...min(size - 1, j + 1) {
                if (x, y) != (i, j) {
                    neighbors.append(self.data[x][y])
                }
            }
        }
        return neighbors
    }
}

func main() {
    let gridSize = 10
    let grid = Grid(size: gridSize)
    let steps = 50
    for _ in 0..<steps {
        grid.update()
    }
}

main()