require 'matrix'

def simulate
  grid = Matrix.build(100, 100) { rand }
  while true
    new_grid = grid.dup
    (1...99).each do |i|
      (1...99).each do |j|
        new_grid[i, j] = 0.25 * (grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1])
      end
    end
    grid = new_grid
  end
end

simulate