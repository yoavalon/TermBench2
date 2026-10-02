class Automaton
  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
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
    (max(0, x - 1)..min(@size, x + 2) - 1).each do |i|
      (max(0, y - 1)..min(@size, y + 2) - 1).each do |j|
        count += 1 if [i, j] != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end
end

class Simulator
  def initialize(automaton)
    @automaton = automaton
  end

  def run
    loop do
      @automaton.update
    end
  end
end

def main
  size = 10
  automaton = Automaton.new(size)
  simulator = Simulator.new(automaton)
  simulator.run
end

main