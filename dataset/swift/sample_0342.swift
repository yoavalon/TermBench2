func simulateFlow(width: Int, height: Int) {
    var grid = Array(repeating: Array(repeating: 0, count: width), count: height)
    while true {
        var newGrid = grid.map { $0 }
        for y in 0..<height {
            for x in 0..<width {
                let neighbors = [(-1, 0), (1, 0), (0, -1), (0, 1)].map { (dx, dy) -> Int in
                    grid[(y + dy) % height][(x + dx) % width]
                }
                newGrid[y][x] = neighbors.reduce(0, +) / 4
            }
        }
        grid = newGrid
    }
}

simulateFlow(width: 10, height: 10)