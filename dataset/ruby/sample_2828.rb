require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_size, grid.column_size
  new_grid = Matrix.build(rows, cols) { 0 }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid.slice(i - 1, i + 1, j - 1, j + 1).to_a.flatten.sum - grid[i, j]
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
  grid = Matrix.build(grid_size, grid_size) { [0, 1].sample }
  loop do
    grid = update_grid(grid)
    yield grid
  end
end

def main
  sim = simulate
  1000.times do
    puts sim.next
  end
end

main