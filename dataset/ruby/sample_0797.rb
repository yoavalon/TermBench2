def update_grid(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  grid.length.times do |i|
    grid[0].length.times do |j|
      count = (i - 1...i + 2).flat_map { |x| (j - 1...j + 2).map { |y| [x, y] } }
                           .select { |x, y| x.between?(0, grid.length - 1) && y.between?(0, grid[0].length - 1) && [x, y] != [i, j] }
                           .map { |x, y| grid[x][y] }
                           .sum
      new_grid[i][j] = grid[i][j] && (count == 2 || count == 3) ? 1 : count == 3
    end
  end
  new_grid
end

def simulate(grid, steps)
  steps.times { grid = update_grid(grid) }
  grid
end

def main
  initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]
  final_grid = simulate(initial_grid, 10)
  final_grid.each { |row| puts row.inspect }
end

main