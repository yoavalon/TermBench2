class AutomataGrid

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_grid = Array.new(@grid.length) { Array.new(@grid.length, 0) }
    (0...@grid.length).each do |i|
      (0...@grid[i].length).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 1
          if neighbors < 2 || neighbors > 3
            new_grid[i][j] = 0
          else
            new_grid[i][j] = 1
          end
        elsif neighbors == 3
          new_grid[i][j] = 1
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)...min(@grid.length, x + 2)).each do |i|
      (max(0, y - 1)...min(@grid[i].length, y + 2)).each do |j|
        count += 1 if [i, j] != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end

end

def boundary_conditions(grid, step_limit)
  steps = 0
  while steps < step_limit
    grid.update
    steps += 1
  end
end

def main
  size = 10
  step_limit = 100
  automata = AutomataGrid.new(size)
  boundary_conditions(automata, step_limit)
end

main if __FILE__ == $0