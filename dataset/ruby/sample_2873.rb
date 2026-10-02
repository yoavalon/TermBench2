require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_count, grid.column_count
  new_grid = Matrix.build(rows, cols) { 0 }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid.minor(i-1..i+1, j-1..j+1).sum - grid[i, j]
      new_grid[i, j] = neighbors == 3 || (neighbors == 2 && grid[i, j]) ? 1 : 0
    end
  end
  new_grid
end

def main
  grid = Matrix.build(50, 50) { 0 }
  grid[25, 25] = 1
  loop do
    grid = update_grid(grid)
  end
end

main