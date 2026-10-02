def cellular_automata(grid, x, y)
  if x < 0 || x >= grid.length || y < 0 || y >= grid[0].length
    return 0
  end
  return grid[x][y] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1)
end

def main
  grid = Array.new(10) { Array.new(10, 0) }
  while true
    for i in 0...grid.length
      for j in 0...grid[0].length
        grid[i][j] = cellular_automata(grid, i, j)
      end
    end
  end
end

main