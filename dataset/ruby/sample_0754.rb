def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = 0
      (-1..1).each do |dy|
        (-1..1).each do |dx|
          neighbors += grid[(y + dy) % height][(x + dx) % width] if [dx, dy] != [0, 0]
        end
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
  width, height, steps = 5, 5, 5
  grid = Array.new(height) { |y| Array.new(width) { |x| (x + y) % 2 == 0 ? 0 : 1 } }
  final_grid = simulate(grid, width, height, steps)
  final_grid.each do |row|
    puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
  end
end

main