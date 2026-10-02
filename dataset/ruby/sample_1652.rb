def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (i-1..i+1).sum do |x|
        (j-1..j+1).sum do |y|
          grid[x][y] if x.between?(0, rows - 1) && y.between?(0, cols - 1) && !(x == i && y == j)
        end
      end
      new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j] == 1)) ? 1 : 0
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
  initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
  simulate(initial_grid)
end

main