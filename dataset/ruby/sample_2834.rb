require 'matrix'

def update_state(grid)
  rows = grid.row_count
  cols = grid.column_count
  new_grid = grid.clone
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (i-1..i+1).sum { |ii| (j-1..j+1).sum { |jj| grid[ii % rows, jj % cols] } } - grid[i, j]
      if grid[i, j] == 1
        if neighbors < 2 || neighbors > 3
          new_grid[i, j] = 0
        end
      elsif neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def main
  size = 100
  grid = Matrix.build(size, size) { rand(2) }
  loop do
    grid = update_state(grid)
  end
end

main