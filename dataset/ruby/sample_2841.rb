def update_grid(grid, rules)
  new_grid = Array.new(grid.size) { Array.new(grid[0].size, 0) }
  (0...grid.size).each do |i|
    (0...grid[0].size).each do |j|
      neighbors = []
      (([i - 1, 0].max)...([i + 2, grid.size].min)).each do |x|
        (([j - 1, 0].max)...([j + 2, grid[0].size].min)).each do |y|
          neighbors << grid[x][y] unless [x, y] == [i, j]
        end
      end
      new_grid[i][j] = rules[neighbors.sort] || 0
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]]
  rules = {
    [0, 0, 0, 0, 0, 0, 0, 0] => 0,
    [1, 1, 1, 1, 1, 1, 1, 1] => 1,
    [0, 0, 0, 1, 1, 1, 0, 0] => 1
  }
  loop do
    grid = update_grid(grid, rules)
  end
end

main