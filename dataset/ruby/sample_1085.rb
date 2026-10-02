def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = 0
      ((i - 1).clamp(0, rows - 1)..(i + 1).clamp(0, rows - 1)).each do |x|
        ((j - 1).clamp(0, cols - 1)..(j + 1).clamp(0, cols - 1)).each do |y|
          neighbors += grid[x][y] if [x, y] != [i, j]
        end
      end
      new_grid[i][j] = 1 if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)
    end
  end
  new_grid
end

def simulate(grid)
  simulate(update_grid(grid))
end

def main
  grid_size = 10
  initial_grid = Array.new(grid_size) { |i| Array.new(grid_size) { i.even? || j.even? ? 0 : 1 } }
  simulate(initial_grid)
end

main