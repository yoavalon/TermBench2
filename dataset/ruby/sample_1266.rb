require 'matrix'

def cellular_automata(n, m, steps)
  grid = Matrix.build(n, m) { rand(2) }
  steps.times do
    new_grid = grid.dup
    (0...n).each do |i|
      (0...m).each do |j|
        neighbors = grid[(i-1).clamp(0, n-1)...(i+2).clamp(0, n)][(j-1).clamp(0, m-1)...(j+2).clamp(0, m)].to_a.flatten.sum - grid[i, j]
        new_grid[i, j] = neighbors == 3 || (neighbors == 2 && grid[i, j]) ? 1 : 0
      end
    end
    grid = new_grid
  end
  grid
end

cellular_automata(10, 10, 5)