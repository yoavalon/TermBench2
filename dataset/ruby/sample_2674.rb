require 'matrix'

class Swarm
  attr_accessor :size, :dimensions, :particles, :best_position, :best_value

  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @particles = Array.new(size) { Particle.new(dimensions) }
    @best_position = nil
    @best_value = Float::INFINITY
  end

  def update_best
    @particles.each do |particle|
      if particle.value < @best_value
        @best_value = particle.value
        @best_position = particle.position.dup
      end
    end
  end

  def optimize(iterations)
    iterations.times do
      @particles.each do |particle|
        particle.update(@best_position)
      end
      update_best
    end
  end
end

class Particle
  attr_accessor :position, :velocity, :best_position, :best_value

  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0..10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_value = calculate_value
  end

  def calculate_value
    @position.map { |x| x ** 2 }.sum
  end

  def update(global_best)
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    @dimensions.times do |i|
      r1 = rand
      r2 = rand
      @velocity[i] = w * @velocity[i] + c1 * r1 * (@best_position[i] - @position[i]) + c2 * r2 * (global_best[i] - @position[i])
      @position[i] += @velocity[i]
    end
    @best_value = calculate_value
    if @best_value < @best_value
      @best_value = @best_value
      @best_position = @position.dup
    end
  end
end

def main
  dimensions = 2
  swarm_size = 30
  iterations = 100
  swarm = Swarm.new(swarm_size, dimensions)
  swarm.optimize(iterations)
  puts "Best position: #{swarm.best_position}"
  puts "Best value: #{swarm.best_value}"
end

main if __FILE__ == $0