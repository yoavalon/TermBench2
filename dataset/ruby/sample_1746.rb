require 'securerandom'

class Particle
  attr_accessor :position, :velocity, :best_position, :best_score

  def initialize(dimensions)
    @position = Array.new(dimensions) { SecureRandom.uniform(-10.0..10.0) }
    @velocity = Array.new(dimensions) { SecureRandom.uniform(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best_position, w=0.7, c1=1.5, c2=1.5)
    @velocity.each_with_index do |_, i|
      r1, r2 = SecureRandom.random_number, SecureRandom.random_number
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best_position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    @position.each_with_index do |_, i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate(cost_function)
    score = cost_function.call(@position)
    if score < @best_score
      @best_score = score
      @best_position = @position.dup
    end
  end
end

class Swarm
  attr_accessor :particles, :global_best_position, :global_best_score

  def initialize(size, dimensions)
    @particles = Array.new(size) { Particle.new(dimensions) }
    @global_best_position = nil
    @global_best_score = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_score < @global_best_score
        @global_best_score = particle.best_score
        @global_best_position = particle.best_position.dup
      end
    end
  end

  def update_swarm
    @particles.each do |particle|
      particle.update_velocity(@global_best_position)
      particle.update_position
    end
  end
end

def cost_function(position)
  position.sum { |x| x ** 2 }
end

def main
  dimensions = 10
  swarm_size = 20
  swarm = Swarm.new(swarm_size, dimensions)
  loop do
    swarm.particles.each do |particle|
      particle.evaluate(method(:cost_function))
    end
    swarm.update_global_best
    swarm.update_swarm
  end
end

main