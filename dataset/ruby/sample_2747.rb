def cellular_automata(x, y, steps)
  grid = Array.new(y) { Array.new(x, 0) }
  steps.times do
    new_grid = grid.map(&:dup)
    y.times do |i|
      x.times do |j|
        neighbors = (-1..1).sum do |di|
          (-1..1).sum do |dj|
            (0 <= i + di && i + di < y && 0 <= j + dj && j + dj < x) ? grid[i + di][j + dj] : 0
          end
        end - grid[i][j]
        new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0
      end
    end
    grid = new_grid
  end
end

def main
  cellular_automata(10, 10, 1000000)
end

main