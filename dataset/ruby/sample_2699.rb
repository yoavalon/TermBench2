class Automaton
  def initialize(grid_size)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @size = grid_size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 0 && neighbors == 3
          new_grid[i][j] = 1
        elsif @grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i][j] = 0
        else
          new_grid[i][j] = @grid[i][j]
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)...min(@size, x + 2)).each do |i|
      (max(0, y - 1)...min(@size, y + 2)).each do |j|
        count += 1 if [i, j] != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end
end

def simulate(automaton, steps)
  steps.times do
    automaton.update
  end
end

def main
  grid_size = 10
  steps = 50
  automaton = Automaton.new(grid_size)
  simulate(automaton, steps)
end

main if __FILE__ == $0