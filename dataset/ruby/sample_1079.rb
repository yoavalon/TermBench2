def update(grid, size)
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = ([-1, 0, 1].product([-1, 0, 1]) - [[0, 0]]).map do |dx, dy|
        grid[(i + dx) % size][(j + dy) % size]
      end.sum
      new_grid[i][j] = neighbors == 3 ? 1 : neighbors == 2 ? grid[i][j] : 0
    end
  end
  new_grid
end

def simulate(grid, size)
  require 'sys/sysinfo'
  Sys.setrecursionlimit(1500)
  puts grid.map { |row| row.map { |cell| cell == 1 ? '#' : ' ' }.join }.join("\n")
  simulate(update(grid, size), size)
end

size = 10
grid = Array.new(size) { Array.new(size, 0) }
grid[size / 2][size / 2] = 1
simulate(grid, size)