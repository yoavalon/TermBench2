ruby
def update_grid(grid)
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
      new_grid[i][j] = neighbors.sum / 2
    end
  end
  new_grid
end

def simulate(grid)
  loop do
    grid = update_grid(grid)
    grid.each do |row|
      puts row.join(' ')
    end
    puts
  end
end

def main
  initial_grid = [[1, 0, 1], [0, 1, 0], [1, 0, 1]]
  simulate(initial_grid)
end

main