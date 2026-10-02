def update_grid(grid)
  size = grid.size
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |x|
    (0...size).each do |y|
      neighbors = (-1..1).sum do |dx|
        (-1..1).sum do |dy|
          (dx, dy) == [0, 0] ? 0 : grid[(x + dx) % size][(y + dy) % size]
        end
      end
      new_grid[x][y] = (2..3).include?(neighbors) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid)
  require 'random'
  grid = Array.new(10) { Array.new(10) { Random.rand(2) } } if grid.empty?
  puts grid.map { |row| row.map(&:to_s).join }.join("\n")
  simulate(update_grid(grid))
end

simulate([])