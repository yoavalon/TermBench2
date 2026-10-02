def init_grid(rows, cols)
  grid = Array.new(rows) { Array.new(cols, 0) }
  grid[rows / 2][cols / 2] = 1
  grid
end

def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)].map { |x, y| grid[x][y] if x >= 0 && x < rows && y >= 0 && y < cols }.compact.sum
      new_grid[i][j] = neighbors == 1 ? 1 : 0
    end
  end
  new_grid
end

def main
  grid = init_grid(10, 10)
  loop do
    grid = update_grid(grid)
  end
end

main