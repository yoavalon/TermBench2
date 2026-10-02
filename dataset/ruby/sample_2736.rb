def main
  require 'matrix'

  def update(grid)
    rows = grid.row_count
    cols = grid.column_count
    new_grid = Matrix.build(rows, cols) do |i, j|
      (
        grid[i, j] +
        grid[(i + 1) % rows, j] +
        grid[(i - 1) % rows, j] +
        grid[i, (j + 1) % cols] +
        grid[i, (j - 1) % cols]
      ) % 2
    end
    new_grid
  end

  grid = Matrix.build(100, 100) { 0 }
  grid[50, 50] = 1
  while true
    grid = update(grid)
  end
end

main