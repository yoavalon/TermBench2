def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (i-1..i+1).sum { |x| (j-1..j+1).sum { |y| grid[x] && grid[x][y] unless [x, y] == [i, j] } }
      new_grid[i][j] = 1 if (2..3).include?(neighbors) || (grid[i][j] == 0 && neighbors == 3)
    end
  end
  new_grid
end

def run_simulation(grid)
  loop do
    grid = update_grid(grid)
  end
end

def main
  initial_grid = [[0, 1, 0], [1, 1, 1], [0, 1, 0]]
  run_simulation(initial_grid)
end

main