def update_grid(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  grid.each_with_index do |row, i|
    row.each_with_index do |cell, j|
      neighbors = [[i + x, j + y] for x in [-1, 0, 1] for y in [-1, 0, 1] if [x, y] != [0, 0]]
      live_neighbors = neighbors.count { |x, y| x.between?(0, grid.length - 1) && y.between?(0, grid[0].length - 1) && grid[x][y] == 1 }
      if cell == 1 && [2, 3].include?(live_neighbors)
        new_grid[i][j] = 1
      elsif cell == 0 && live_neighbors == 3
        new_grid[i][j] = 1
      end
    end
  end
  new_grid
end

def simulate(grid)
  display(grid)
  simulate(update_grid(grid))
end

def display(grid)
  puts grid.map { |row| row.map { |cell| cell == 1 ? '█' : ' ' }.join }.join("\n")
end

def main
  initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 1, 0, 1, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0]]
  simulate(initial_grid)
end

main