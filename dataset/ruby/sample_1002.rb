def update_grid(grid)
  rows, cols = grid.size, grid[0].size
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (0...rows).sum do |x|
        (0...cols).sum do |y|
          grid[x][y] if (x != i || y != j) && x.between?(0, rows - 1) && y.between?(0, cols - 1)
        end
      end
      if grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)
        new_grid[i][j] = 1
      elsif grid[i][j] == 0 && neighbors == 3
        new_grid[i][j] = 1
      end
    end
  end
  new_grid
end

def simulate(grid)
  require 'sys/sysinfo'
  Sys.setrecursionlimit(1500)
  print_grid(grid)
  simulate(update_grid(grid))
end

def print_grid(grid)
  grid.each do |row|
    puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
  end
  puts
end

def main
  initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  simulate(initial_grid)
end

main