def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (0...rows).sum { |x| (0...cols).sum { |y| grid[x][y] if [x, y] != [i, j] } }
      if grid[i][j] == 1
        new_grid[i][j] = 1 if neighbors.between?(2, 3)
      else
        new_grid[i][j] = 1 if neighbors == 3
      end
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