def update_grid(grid, size)
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = 0
      (max(0, i - 1)...min(size, i + 2)).each do |x|
        (max(0, j - 1)...min(size, j + 2)).each do |y|
          neighbors += grid[x][y] if [x, y] != [i, j]
        end
      end
      new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid, size, steps)
  return grid if steps == 0
  simulate(update_grid(grid, size), size, steps - 1)
end

def main
  size = 10
  initial_grid = Array.new(size) { Array.new(size, 0) }
  initial_grid[5][5], initial_grid[5][6], initial_grid[6][5], initial_grid[6][6] = [1, 1, 1, 1]
  final_grid = simulate(initial_grid, size, 10)
  final_grid.each do |row|
    puts row.join(' ')
  end
end

main