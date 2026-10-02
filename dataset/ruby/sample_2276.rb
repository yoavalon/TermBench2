require 'matrix'

def update_grid(grid)
  new_grid = Matrix.build(grid.row_count, grid.column_count) { 0 }
  (1...grid.row_count - 1).each do |i|
    (1...grid.column_count - 1).each do |j|
      neighbors = grid[i - 1, j - 1] + grid[i - 1, j] + grid[i - 1, j + 1] +
                  grid[i, j - 1] + grid[i, j + 1] +
                  grid[i + 1, j - 1] + grid[i + 1, j] + grid[i + 1, j + 1]
      if grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
        new_grid[i, j] = 1
      else
        new_grid[i, j] = grid[i, j]
      end
    end
  end
  new_grid
end

def simulate
  grid_size = 50
  grid = Matrix.build(grid_size, grid_size) { rand(2) }
  loop do
    grid = update_grid(grid)
  end
end

simulate