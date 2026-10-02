require 'matrix'

class Automaton
  def initialize(size)
    @grid = Matrix.build(size, size) { 0 }
    @size = size
  end

  def update
    new_grid = @grid.dup
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = @grid[(i - 1) % @size, (j - 1) % @size] +
                    @grid[(i - 1) % @size, j] +
                    @grid[(i - 1) % @size, (j + 1) % @size] +
                    @grid[i, (j - 1) % @size] +
                    @grid[i, (j + 1) % @size] +
                    @grid[(i + 1) % @size, (j - 1) % @size] +
                    @grid[(i + 1) % @size, j] +
                    @grid[(i + 1) % @size, (j + 1) % @size]
        if @grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i, j] = 0
        elsif @grid[i, j] == 0 && neighbors == 3
          new_grid[i, j] = 1
        end
      end
    end
    @grid = new_grid
  end
end

class BoundaryHandler
  def initialize(automaton)
    @automaton = automaton
  end

  def apply_boundary_conditions
    @automaton.grid.row(0).each_with_index { |_, j| @automaton.grid[0, j] = 0 }
    @automaton.grid.row(@automaton.size - 1).each_with_index { |_, j| @automaton.grid[@automaton.size - 1, j] = 0 }
    @automaton.grid.column(0).each_with_index { |_, i| @automaton.grid[i, 0] = 0 }
    @automaton.grid.column(@automaton.size - 1).each_with_index { |_, i| @automaton.grid[i, @automaton.size - 1] = 0 }
  end
end

def main
  size = 100
  automaton = Automaton.new(size)
  boundary_handler = BoundaryHandler.new(automaton)
  automaton.grid[1, 2] = 1
  automaton.grid[2, 3] = 1
  automaton.grid[3, 1] = 1
  automaton.grid[3, 2] = 1
  automaton.grid[3, 3] = 1
  loop do
    boundary_handler.apply_boundary_conditions
    automaton.update
  end
end

main