def update_state(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)].sum { |x, y| (0 <= x && x < grid.length && 0 <= y && y < grid[0].length) ? grid[x][y] : 0 }
      new_grid[i][j] = (neighbors == 3 || (grid[i][j] && neighbors == 2)) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid)
  loop do
    grid = update_state(grid)
    grid.each do |row|
      puts row.map(&:to_s).join(' ')
    end
    puts
  end
end

def main
  initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 0, 0], [0, 1, 1, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
  simulate(initial_grid)
end

main