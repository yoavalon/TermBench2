def cellular_automata(grid, steps)
  steps.times do
    new_grid = Array.new(grid.size) { Array.new(grid[0].size, 0) }
    grid.size.times do |i|
      grid[0].size.times do |j|
        neighbors = 0
        [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]].each do |x, y|
          neighbors += grid[x][y] if x.between?(0, grid.size - 1) && y.between?(0, grid[0].size - 1)
        end
        new_grid[i][j] = 1 if neighbors == 2 || (neighbors == 3 && grid[i][j] == 1)
      end
    end
    grid = new_grid
  end
  grid
end

initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
steps = 5
result = cellular_automata(initial_grid, steps)
puts result