require 'matrix'

def init_grid(size)
  grid = Matrix.build(size, size) { 0 }
  grid[size / 2, size / 2] = 1
  grid
end

def update_grid(grid)
  new_grid = grid.clone
  (0...grid.row_count).each do |i|
    (0...grid.column_count).each do |j|
      neighbors = ([-1, 0, 1].map { |di| [i + di, j - 1, j, j + 1] }.flatten - [i, j]).count { |x, y| grid[x, y] == 1 }
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
  size = 10
  grid = init_grid(size)
  steps = 50
  steps.times do
    grid = update_grid(grid)
  end
  puts grid.to_a
end

main