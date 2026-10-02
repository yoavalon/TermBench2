def update_state(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0.0) }
  for i in 0...grid.length
    for j in 0...grid[0].length
      neighbors = 0
      for x in [-1, 0, 1]
        for y in [-1, 0, 1]
          next if x == 0 && y == 0
          ni, nj = (i + x), (j + y)
          neighbors += grid[ni][nj] if ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length
        end
      end
      new_grid[i][j] = neighbors / 9.0
    end
  end
  new_grid
end

def run_simulation(steps, size)
  grid = Array.new(size) { Array.new(size) { |i, j| i == j ? 1.0 : 0.0 } }
  steps.times do
    grid = update_state(grid)
  end
  grid
end

if __FILE__ == $0
  result = run_simulation(10, 5)
  result.each { |row| puts row.inspect }
end