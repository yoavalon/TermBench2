def update_state(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = 0
      (-1..1).each do |dy|
        (-1..1).each do |dx|
          next if dy == 0 && dx == 0
          nx, ny = (x + dx), (y + dy)
          neighbors += grid[ny][nx] if nx >= 0 && nx < width && ny >= 0 && ny < height
        end
      end
      if grid[y][x] == 1
        new_grid[y][x] = (2 <= neighbors && neighbors <= 3) ? 1 : 0
      else
        new_grid[y][x] = (neighbors == 3) ? 1 : 0
      end
    end
  end
  new_grid
end

def simulate(grid, width, height, steps)
  return grid if steps == 0
  simulate(update_state(grid, width, height), width, height, steps - 1)
end

def main
  width, height, steps = 50, 50, 100
  grid = Array.new(height) { |y| Array.new(width) { |x| (x + y) % 2 ? 1 : 0 } }
  final_grid = simulate(grid, width, height, steps)
  final_grid.each do |row|
    puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
  end
end

main