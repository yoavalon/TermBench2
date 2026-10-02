def cellular_automata(n, m)
  grid = Array.new(n) { Array.new(m, 0) }
  while true
    new_grid = Array.new(n) { Array.new(m, 0) }
    (0...n).each do |i|
      (0...m).each do |j|
        state = grid[i][j]
        neighbors = (i - 1...i + 2).flat_map do |x|
          (j - 1...j + 2).map do |y|
            grid[x][y] if x.between?(0, n - 1) && y.between?(0, m - 1)
          end.compact.sum
        end - state
        new_grid[i][j] = (neighbors == 3 || (state != 0 && neighbors == 2)) ? 1 : 0
      end
    end
    grid = new_grid
  end
end

def main
  cellular_automata(10, 10)
end

main