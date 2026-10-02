def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0.0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = []
      [-1, 0, 1].each do |dy|
        [-1, 0, 1].each do |dx|
          neighbors << grid[(y + dy) % height][(x + dx) % width] if dy != 0 || dx != 0
        end
      end
      new_grid[y][x] = neighbors.sum / neighbors.size
    end
  end
  new_grid
end

def simulate(width, height, steps)
  grid = (0...height).map { |y| (0...width).map { |x| x.to_f + y.to_f } }
  steps.times do
    grid = update_grid(grid, width, height)
  end
  grid
end

def main
  width, height, steps = 10, 10, 5
  final_grid = simulate(width, height, steps)
  final_grid.each { |row| puts row.inspect }
end

main