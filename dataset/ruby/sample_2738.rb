def cellular_automata
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  while true
    new_grid = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    (0..2).each do |i|
      (0..2).each do |j|
        live_neighbors = 0
        (-1..1).each do |x|
          (-1..1).each do |y|
            if (0 <= x + i && x + i < 3) && (0 <= y + j && y + j < 3) && (x + i != i || y + j != j) && grid[x + i][y + j] == 1
              live_neighbors += 1
            end
          end
        end
        new_grid[i][j] = live_neighbors == 2 ? 1 : 0
      end
    end
    grid = new_grid
  end
end

cellular_automata