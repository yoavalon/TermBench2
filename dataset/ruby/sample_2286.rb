require 'matrix'

def update_grid(grid)
  new_grid = grid.clone
  (1...grid.row_count - 1).each do |i|
    (1...grid.column_count - 1).each do |j|
      neighbors = grid.minor([i-1, i, i+1], [j-1, j, j+1]).sum - grid[i, j]
      if grid[i, j] == 1
        new_grid[i, j] = neighbors == 2 || neighbors == 3 ? 1 : 0
      else
        new_grid[i, j] = neighbors == 3 ? 1 : 0
      end
    end
  end
  new_grid
end

def main
  grid_size = 50
  grid = Matrix.build(grid_size, grid_size) { [0, 1].sample }
  loop do
    grid = update_grid(grid)
  end
end

main