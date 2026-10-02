class CellularAutomata

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    for i in 0...@size
      for j in 0...@size
        state = @grid[i][j]
        neighbors = count_neighbors(i, j)
        if state == 0 && neighbors == 3
          new_grid[i][j] = 1
        elsif state == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i][j] = 0
        else
          new_grid[i][j] = state
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    for i in [x - 1, x, x + 1].select { |i| i >= 0 && i < @size }
      for j in [y - 1, y, y + 1].select { |j| j >= 0 && j < @size }
        if [i, j] != [x, y] && @grid[i][j] == 1
          count += 1
        end
      end
    end
    count
  end

end

class Simulation

  def initialize(size)
    @automata = CellularAutomata.new(size)
    @size = size
  end

  def run
    loop do
      @automata.update
    end
  end

end

def main
  simulation = Simulation.new(10)
  simulation.run
end

main