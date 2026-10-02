def update_state(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = [
        grid[(i - 1) % grid.length][(j - 1) % grid[0].length],
        grid[(i - 1) % grid.length][j],
        grid[(i - 1) % grid.length][(j + 1) % grid[0].length],
        grid[i][(j - 1) % grid[0].length],
        grid[i][(j + 1) % grid[0].length],
        grid[(i + 1) % grid.length][(j - 1) % grid[0].length],
        grid[(i + 1) % grid.length][j],
        grid[(i + 1) % grid.length][(j + 1) % grid[0].length]
      ]
      live_neighbors = neighbors.sum
      if grid[i][j] == 1
        if live_neighbors < 2 || live_neighbors > 3
          new_grid[i][j] = 0
        else
          new_grid[i][j] = 1
        end
      elsif live_neighbors == 3
        new_grid[i][j] = 1
      else
        new_grid[i][j] = 0
      end
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
  loop do
    grid = update_state(grid)
    grid.each do |row|
      puts row.join(' ')
    end
    puts
  end
end

main