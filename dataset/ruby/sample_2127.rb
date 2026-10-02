def cellular_automata(n)
  grid = Array.new(n) { Array.new(n, 0) }
  loop do
    next_grid = Array.new(n) { Array.new(n, 0) }
    (0...n).each do |i|
      (0...n).each do |j|
        neighbors = (0...3).sum do |x|
          (0...3).sum do |y|
            grid[(i + x - 1) % n][(j + y - 1) % n] unless [x, y] == [1, 1]
          end
        end
        next_grid[i][j] = 1 if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)
      end
    end
    grid = next_grid
  end
end

cellular_automata(10)