def cellular_automata(width, height)
  require 'matrix'
  grid = Matrix.build(height, width) { 0 }
  loop do
    new_grid = grid.dup
    (1...height - 1).each do |i|
      (1...width - 1).each do |j|
        neighbors = grid.minor([i-1, i, i+1], [j-1, j, j+1]).to_a.flatten.sum - grid[i, j]
        if grid[i, j] != 0 && (neighbors < 2 || neighbors > 3)
          new_grid[i, j] = 0
        elsif grid[i, j] == 0 && neighbors == 3
          new_grid[i, j] = 1
        end
      end
    end
    grid = new_grid
  end
end

cellular_automata(50, 50)