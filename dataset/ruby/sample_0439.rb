require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_count, grid.column_count
  new_grid = grid.dup
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid.minor(i-1..i+1, j-1..j+1).sum - grid[i, j]
      if grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def main
  size = 50
  grid = Matrix.build(size, size) { [0, 1].sample }
  loop do
    grid = update_grid(grid)
  end
end

main