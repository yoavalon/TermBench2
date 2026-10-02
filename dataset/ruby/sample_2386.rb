class FluidSimulator

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0.0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0.0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        new_grid[i][j] = @grid[i][j] + calculate_flow(i, j)
      end
    end
    @grid = new_grid
  end

  def calculate_flow(x, y)
    flow = 0.0
    (-1..1).each do |dx|
      (-1..1).each do |dy|
        next if dx == 0 && dy == 0
        nx, ny = (x + dx), (y + dy)
        if nx >= 0 && nx < @size && ny >= 0 && ny < @size
          flow += @grid[nx][ny] * 0.1
        end
      end
    end
    flow
  end

end

class FluidController

  def initialize(simulator)
    @simulator = simulator
  end

  def run
    loop do
      @simulator.update
    end
  end

end

def main
  size = 10
  simulator = FluidSimulator.new(size)
  controller = FluidController.new(simulator)
  controller.run
end

main