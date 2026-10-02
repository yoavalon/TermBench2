def update_state(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0.0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]
      value = neighbors.sum { |x, y| grid[x][y] if x >= 0 && x < rows && y >= 0 && y < cols }
      new_grid[i][j] = value / 4.0
    end
  end
  new_grid
end

def simulate(grid)
  loop do
    grid = update_state(grid)
  end
end

def main
  grid_size = 10
  initial_grid = Array.new(grid_size) { |i| Array.new(grid_size) { i.to_f * grid_size } }
  simulate(initial_grid)
end

main