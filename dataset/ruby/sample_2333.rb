ruby
class FluidSim
  def initialize(size, diffusion_rate)
    @size = size
    @grid = Array.new(size) { Array.new(size, 0.0) }
    @diffusion_rate = diffusion_rate
  end

  def update_grid
    new_grid = Array.new(@size) { Array.new(@size, 0.0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        total = @grid[i][j]
        neighbors = 0
        if i > 0
          total += @grid[i - 1][j]
          neighbors += 1
        end
        if i < @size - 1
          total += @grid[i + 1][j]
          neighbors += 1
        end
        if j > 0
          total += @grid[i][j - 1]
          neighbors += 1
        end
        if j < @size - 1
          total += @grid[i][j + 1]
          neighbors += 1
        end
        new_grid[i][j] = @grid[i][j] + @diffusion_rate * (total.to_f / neighbors - @grid[i][j])
      end
    end
    @grid = new_grid
  end

  def add_source(x, y, amount)
    @grid[x][y] += amount
  end
end

class SimulationRunner
  def initialize(sim)
    @sim = sim
  end

  def run
    loop do
      @sim.update_grid
      @sim.add_source(@sim.size / 2, @sim.size / 2, 0.1)
    end
  end
end

def main
  sim = FluidSim.new(100, 0.01)
  runner = SimulationRunner.new(sim)
  runner.run
end

main