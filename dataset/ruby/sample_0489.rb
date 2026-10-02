def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].sum do |dx, dy|
        grid[(y + dy) % height][(x + dx) % width]
      end
      if grid[y][x] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[y][x] = 0
      elsif grid[y][x] == 0 && neighbors == 3
        new_grid[y][x] = 1
      else
        new_grid[y][x] = grid[y][x]
      end
    end
  end
  new_grid
end

def main
  width, height = 10, 10
  grid = Array.new(height) { |y| Array.new(width) { |x| (x + y) % 2 } }
  loop do
    grid = update_grid(grid, width, height)
  end
end

main