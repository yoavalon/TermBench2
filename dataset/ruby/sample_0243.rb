require 'matrix'

class Automata
  def initialize(size, boundary_type)
    @grid = Matrix.build(size, size) { 0 }
    @boundary_type = boundary_type
    @size = size
  end

  def apply_boundary_conditions
    if @boundary_type == 'fixed'
      @grid.column(0).each_with_index { |_, i| @grid[i, 0] = 1 }
      @grid.column(@size - 1).each_with_index { |_, i| @grid[i, @size - 1] = 1 }
      @grid.row(0).each_with_index { |_, j| @grid[0, j] = 1 }
      @grid.row(@size - 1).each_with_index { |_, j| @grid[@size - 1, j] = 1 }
    elsif @boundary_type == 'periodic'
      @grid.column(0).each_with_index { |_, i| @grid[i, 0] = @grid[i, @size - 2] }
      @grid.column(@size - 1).each_with_index { |_, i| @grid[i, @size - 1] = @grid[i, 1] }
      @grid.row(0).each_with_index { |_, j| @grid[0, j] = @grid[@size - 2, j] }
      @grid.row(@size - 1).each_with_index { |_, j| @grid[@size - 1, j] = @grid[1, j] }
    end
  end

  def update_grid
    new_grid = @grid.dup
    (1...@size - 1).each do |i|
      (1...@size - 1).each do |j|
        neighbors = @grid.minor([i - 1, i, i + 1], [j - 1, j, j + 1]).sum - @grid[i, j]
        if @grid[i, j] == 1
          new_grid[i, j] = 0 if neighbors < 2 || neighbors > 3
        else
          new_grid[i, j] = 1 if neighbors == 3
        end
      end
    end
    @grid = new_grid
  end
end

class Simulation
  def initialize(automata, steps)
    @automata = automata
    @steps = steps
  end

  def run
    @steps.times do
      @automata.apply_boundary_conditions
      @automata.update_grid
    end
  end
end

def main
  size = 10
  boundary_type = 'fixed'
  steps = 50
  automata = Automata.new(size, boundary_type)
  simulation = Simulation.new(automata, steps)
  simulation.run
end

main if __FILE__ == $0