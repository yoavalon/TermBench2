def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].sum do |dx, dy|
        grid[(y + dy) % height][(x + dx) % width]
      end
      new_grid[y][x] = (neighbors == 3 || (grid[y][x] == 1 && neighbors == 2)) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid, width, height, steps)
  return grid if steps == 0
  simulate(update_grid(grid, width, height), width, height, steps - 1)
end

def main
  width, height = 10, 10
  initial_grid = Array.new(height) { |y| Array.new(width) { |x| x % 2 == 0 ? 1 : 0 } }
  steps = 5
  final_grid = simulate(initial_grid, width, height, steps)
  final_grid.each do |row|
    puts row.join(' ')
  end
end

main