require 'matrix'

def update_grid(grid)
  new_grid = grid.dup
  rows, cols = grid.row_count, grid.column_count
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid[max(0, i - 1)...min(rows, i + 2), max(0, j - 1)...min(cols, j + 2)].sum - grid[i, j]
      if grid[i, j] == 1
        new_grid[i, j] = 1 if (2..3).include?(neighbors)
      else
        new_grid[i, j] = 1 if neighbors == 3
      end
    end
  end
  new_grid
end

def main
  grid_size = 10
  grid = Matrix.build(grid_size, grid_size) { 0 }
  grid[grid_size / 2, grid_size / 2] = 1
  steps = 50
  steps.times do
    grid = update_grid(grid)
  end
  puts grid
end

main