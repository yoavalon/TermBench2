def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = (0...3).flat_map { |dy| (0...3).map { |dx| [dx, dy] } }
                          .reject { |dx, dy| dx == 0 && dy == 0 }
                          .map { |dx, dy| grid[(y + dy) % height][(x + dx) % width] }
                          .sum
      if grid[y][x] != 0
        new_grid[y][x] = neighbors == 2 || neighbors == 3
      else
        new_grid[y][x] = neighbors == 3
      end
    end
  end
  new_grid
end

def main
  width, height = 50, 50
  grid = (0...height).map { |y| (0...width).map { |x| (x + y) % 2 == 0 ? 1 : 0 } }
  loop do
    grid = update_grid(grid, width, height)
  end
end

main