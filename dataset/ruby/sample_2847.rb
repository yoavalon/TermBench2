require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_count, grid.column_count
  new_grid = grid.dup
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid[i, (j - 1) % cols] + grid[i, (j + 1) % cols] + grid[(i - 1) % rows, j] + grid[(i + 1) % rows, j] + grid[(i - 1) % rows, (j - 1) % cols] + grid[(i - 1) % rows, (j + 1) % cols] + grid[(i + 1) % rows, (j - 1) % cols] + grid[(i + 1) % rows, (j + 1) % cols]
      if grid[i, j] == 1
        new_grid[i, j] = 0 if neighbors < 2 || neighbors > 3
      elsif neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def main
  grid_size = 10
  grid = Matrix.build(grid_size, grid_size) { rand(2) }
  loop do
    grid = update_grid(grid)
    puts grid.to_a.map { |row| row.join(' ') }.join("\n")
    puts '-' * 20
  end
end

main