def update_grid(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = (0...grid.length).sum do |x|
        (0...grid[0].length).sum do |y|
          grid[x][y] if (x != i || y != j) && x.between?(0, grid.length - 1) && y.between?(0, grid[0].length - 1)
        end
      end
      new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0
    end
  end
  new_grid
end

def cellular_automata
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    grid = update_grid(grid)
    grid.each do |row|
      puts row.map(&:to_s).join(' ')
    end
    puts
  end
end

cellular_automata