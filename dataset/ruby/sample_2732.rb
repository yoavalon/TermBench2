def simulate(grid, rules)
  while true
    new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
    (0...grid.length).each do |i|
      (0...grid[0].length).each do |j|
        neighbors = []
        [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].each do |dx, dy|
          neighbors << (0 <= i + dx && i + dx < grid.length && 0 <= j + dy && j + dy < grid[0].length ? grid[i + dx][j + dy] : 0)
        end
        new_grid[i][j] = rules[neighbors.sum]
      end
    end
    grid = new_grid
  end
end

def main
  initial_grid = [[0, 1, 0], [0, 0, 1], [1, 1, 1]]
  transition_rules = [0, 1, 1, 1, 0, 0, 0, 0, 0]
  simulate(initial_grid, transition_rules)
end

main