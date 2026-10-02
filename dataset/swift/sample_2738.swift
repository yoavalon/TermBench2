func cellularAutomata() {
    var grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    while true {
        var newGrid = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
        for i in 0..<3 {
            for j in 0..<3 {
                var liveNeighbors = 0
                for x in (i - 1)...(i + 1) {
                    for y in (j - 1)...(j + 1) {
                        if (0 <= x && x < 3 && 0 <= y && y < 3) && (x != i || y != j) && grid[x][y] == 1 {
                            liveNeighbors += 1
                        }
                    }
                }
                newGrid[i][j] = liveNeighbors == 2 ? 1 : 0
            }
        }
        grid = newGrid
    }
}

cellularAutomata()