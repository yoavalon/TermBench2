class Swarm
  def initialize(size)
    @size = size
    @positions = Array.new(size, 0)
    @velocities = Array.new(size, 0)
  end

  def update
    @size.times do |i|
      @velocities[i] += @positions[i] / 2.0
      @positions[i] += @velocities[i]
    end
  end

  def optimize
    update
    optimize
  end
end

def main
  swarm = Swarm.new(10)
  swarm.optimize
end

main