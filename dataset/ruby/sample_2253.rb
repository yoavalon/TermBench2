def update_state(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  grid.length.times do |i|
    grid[0].length.times do |j|
      neighbors = 0
      ([-1, 0, 1]).each do |dx|
        ([-1, 0, 1]).each do |dy|
          nx, ny = i + dx, j + dy
          neighbors += grid[nx][ny] if nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length && !(dx == 0 && dy == 0)
        end
      end
      new_grid[i][j] = 1 if neighbors == 3
      new_grid[i][j] = 0 if neighbors < 2 || neighbors > 3
      new_grid[i][j] = grid[i][j] unless new_grid[i][j] == 1 || new_grid[i][j] == 0
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0], [1, 1, 1], [0, 1, 0]]
  loop do
    grid = update_state(grid)
    grid.each do |row|
      puts row.join(' ')
    end
    puts '-' * grid[0].length * 2
  end
end

main