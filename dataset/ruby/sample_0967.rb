def cellular_automata(grid, rule)
  new_grid = Array.new(grid.size) { Array.new(grid[0].size, 0) }
  grid.size.times do |i|
    grid[0].size.times do |j|
      neighbors = []
      (-1..1).each do |x|
        (-1..1).each do |y|
          neighbors << grid[(i + x) % grid.size][(j + y) % grid[0].size] if [x, y] != [0, 0]
        end
      end
      new_grid[i][j] = rule.call(neighbors.sort)
    end
  end
  cellular_automata(new_grid, rule)
end

def main
  initial_grid = Array.new(10) { |i| Array.new(10) { |j| i == j ? 1 : 0 } }
  rule = ->(n) { n.sum == 3 ? 1 : 0 }
  cellular_automata(initial_grid, rule)
end

main