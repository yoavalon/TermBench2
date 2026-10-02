require 'matrix'

class CellularAutomata
  def initialize(size, rule)
    @grid = Matrix.build(size, size) { 0.0 }
    @grid[size / 2, size / 2] = 1.0
    @rule = rule
  end

  def apply_rule(neighborhood)
    s = neighborhood.sum
    if s == 3
      1.0
    elsif s == 2
      @grid[neighborhood.row_size / 2, neighborhood.column_size / 2]
    else
      0.0
    end
  end

  def update_grid
    new_grid = Matrix.build(@grid.row_size, @grid.column_size) { 0.0 }
    (1...@grid.row_size - 1).each do |i|
      (1...@grid.column_size - 1).each do |j|
        neighborhood = @grid.minor((i - 1)..(i + 1), (j - 1)..(j + 1))
        new_grid[i, j] = apply_rule(neighborhood)
      end
    end
    @grid = new_grid
  end
end

class FluidSimulation
  def initialize(size, rule)
    @ca = CellularAutomata.new(size, rule)
  end

  def simulate
    loop do
      @ca.update_grid
    end
  end
end

def main
  sim = FluidSimulation.new(50, 30)
  sim.simulate
end

main