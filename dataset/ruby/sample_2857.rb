def update_state(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |r|
    (0...cols).each do |c|
      neighbors = [[r - 1, c], [r + 1, c], [r, c - 1], [r, c + 1]].select { |x, y| x.between?(0, rows - 1) && y.between?(0, cols - 1) }.map { |x, y| grid[x][y] }
      new_grid[r][c] = neighbors.sum == 3 ? 1 : grid[r][c]
    end
  end
  new_grid
end

def run_simulation
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    grid = update_state(grid)
    grid.each do |row|
      puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
    end
    puts
  end
end

run_simulation