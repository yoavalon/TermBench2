def update_state(grid)
  new_grid = grid.map { |row| row.dup }
  grid.each_with_index do |row, y|
    row.each_with_index do |cell, x|
      neighbors = []
      (-1..1).each do |dy|
        (-1..1).each do |dx|
          next if dy == 0 && dx == 0
          ny, nx = y + dy, x + dx
          neighbors << grid[ny][nx] if ny.between?(0, grid.length - 1) && nx.between?(0, row.length - 1)
        end
      end
      count = neighbors.sum
      if cell == 1 && count < 2
        new_grid[y][x] = 0
      elsif cell == 1 && (count == 2 || count == 3)
        new_grid[y][x] = 1
      elsif cell == 1 && count > 3
        new_grid[y][x] = 0
      elsif cell == 0 && count == 3
        new_grid[y][x] = 1
      end
    end
  end
  new_grid
end

def display_grid(grid)
  grid.each do |row|
    puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
  end
  puts
end

def simulate(grid)
  display_grid(grid)
  simulate(update_state(grid))
end

def main
  initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 0, 0], [0, 1, 0, 1, 0], [0, 0, 1, 1, 0], [0, 0, 0, 0, 0]]
  simulate(initial_grid)
end

main