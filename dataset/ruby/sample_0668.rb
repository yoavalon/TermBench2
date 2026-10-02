def cellular_automata(grid, steps)
  return grid if steps == 0
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)].sum { |x, y| grid[x][y] if x.between?(0, grid.length - 1) && y.between?(0, grid[0].length - 1) }
      new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0
    end
  end
  cellular_automata(new_grid, steps - 1)
end

grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 1, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]
result = cellular_automata(grid, 10)
result.each { |row| puts row.inspect }