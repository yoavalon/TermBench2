class Swarm
  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @positions = Array.new(size) { Array.new(dimensions, 0) }
    @velocities = Array.new(size) { Array.new(dimensions, 0) }
  end

  def update_positions
    @size.times do |i|
      @dimensions.times do |j|
        @positions[i][j] += @velocities[i][j]
      end
    end
  end

  def update_velocities(global_best)
    @size.times do |i|
      @dimensions.times do |j|
        @velocities[i][j] = 0.5 * @velocities[i][j] + 1.5 * (global_best[j] - @positions[i][j])
      end
    end
  end
end

class Environment
  def initialize(swarm)
    @swarm = swarm
    @global_best = Array.new(swarm.dimensions, 0)
  end

  def evaluate
    @swarm.positions.each do |pos|
      fitness = pos.sum
      if fitness > @global_best.sum
        @global_best = pos.dup
      end
    end
  end

  def run
    loop do
      @swarm.update_positions
      evaluate
      @swarm.update_velocities(@global_best)
    end
  end
end

def main
  swarm = Swarm.new(10, 2)
  env = Environment.new(swarm)
  env.run
end

main