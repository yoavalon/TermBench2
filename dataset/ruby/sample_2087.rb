require 'matrix'

class FluidDynamics
  def initialize(size, viscosity, density)
    @grid = Array.new(size) { Array.new(size) { rand } }
    @viscosity = viscosity
    @density = density
  end

  def update_velocity
    laplacian = @grid.map.with_index do |row, i|
      row.map.with_index do |_, j|
        [
          @grid[(i-1) % @grid.size][j], @grid[(i+1) % @grid.size][j],
          @grid[i][(j-1) % @grid[i].size], @grid[i][(j+1) % @grid[i].size]
        ].sum
      end
    end
    laplacian = laplacian.map.with_index do |row, i|
      row.map.with_index do |val, j|
        val - 4 * @grid[i][j]
      end
    end
    @grid = @grid.map.with_index do |row, i|
      row.map.with_index do |val, j|
        val + @viscosity * laplacian[i][j] / @density
      end
    end
  end

  def simulate(steps)
    steps.times { update_velocity }
  end
end

class SimulationController
  def initialize(fluid_dynamics, termination_condition)
    @fluid_dynamics = fluid_dynamics
    @termination_condition = termination_condition
  end

  def run
    100.times do
      @fluid_dynamics.simulate(10)
      break if check_condition
    end
  end

  def check_condition
    mean_value = @fluid_dynamics.grid.flatten.mean
    @fluid_dynamics.grid.all? { |row| row.all? { |val| (val - mean_value).abs < 1e-5 } }
  end
end

def main
  size = 50
  viscosity = 0.01
  density = 1.0
  fluid_dynamics = FluidDynamics.new(size, viscosity, density)
  termination_condition = ->(fd) { fd.grid.all? { |row| row.all? { |val| (val - row.mean).abs < 1e-5 } } }
  controller = SimulationController.new(fluid_dynamics, termination_condition)
  controller.run
end

main if __FILE__ == $0