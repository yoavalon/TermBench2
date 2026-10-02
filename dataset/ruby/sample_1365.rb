def update_grid(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  grid.each_with_index do |row, i|
    row.each_with_index do |cell, j|
      neighbors = [(-1..1).map { |x| [(i + x), (-1..1).map { |y| [(j + y), (grid[x] && grid[x][y])].compact } }.compact }.flatten(1) - [[i, j]]
      live_neighbors = neighbors.count { |x, y| grid[x] && grid[x][y] }
      new_grid[i][j] = (live_neighbors == 3 || (cell == 1 && live_neighbors == 2)) ? 1 : 0
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  10.times do
    grid = update_grid(grid)
    puts grid.map { |row| row.map { |cell| cell == 1 ? 'X' : ' ' }.join }.join("\n")
    puts
  end
end

main