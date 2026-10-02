def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (max(0, i - 1)..min(rows - 1, i + 1)).sum do |x|
        (max(0, j - 1)..min(cols - 1, j + 1)).sum do |y|
          grid[x][y] unless [x, y] == [i, j]
        end
      end
      new_grid[i][j] = (neighbors == 3) ? 1 : (grid[i][j] && neighbors == 2)
    end
  end
  new_grid
end

def simulate(grid)
  loop do
    grid = update_grid(grid)
  end
end

def main
  initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  simulate(initial_grid)
end

main