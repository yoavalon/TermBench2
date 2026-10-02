ruby
def cellular_automata
  grid = Array.new(10) { Array.new(10, 0) }
  loop do
    (1...9).each do |i|
      (1...9).each do |j|
        grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) % 2
      end
    end
    (0...10).each do |i|
      grid[i][0] = grid[i][9]
      grid[i][9] = grid[i][0]
      grid[0][i] = grid[9][i]
      grid[9][i] = grid[0][i]
    end
  end
end

cellular_automata