def update_grid(grid, rule)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = []
      [-1, 0, 1].each do |di|
        [-1, 0, 1].each do |dj|
          next if di == 0 && dj == 0
          neighbors << grid[(i + di) % grid.length][(j + dj) % grid[0].length]
        end
      end
      new_grid[i][j] = rule.call(neighbors, grid[i][j])
    end
  end
  new_grid
end

def evolve(grid, rule, steps)
  steps.times do
    grid = update_grid(grid, rule)
  end
  grid
end

def main
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]

  rule = lambda do |neighbors, cell|
    1 if neighbors.sum == 3 else 0
  end

  loop do
    grid = evolve(grid, rule, 1)
  end
end

main