require 'matrix'
require 'securerandom'

class Swarm
  attr_accessor :size, :dimensions, :particles, :global_best

  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @particles = Array.new(size) { Particle.new(dimensions) }
    @global_best = nil
  end

  def update_global_best
    @particles.each do |particle|
      if @global_best.nil? || particle.best_score < @global_best.best_score
        @global_best = particle
      end
    end
  end

  def update_particles
    @particles.each do |particle|
      particle.update_velocity(@global_best)
      particle.update_position
    end
  end
end

class Particle
  attr_accessor :position, :velocity, :best_position, :best_score

  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0..10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best)
    w = 0.729
    c1 = 1.494
    c2 = 1.494
    dimensions.times do |i|
      r1, r2 = SecureRandom.random_number, SecureRandom.random_number
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best.best_position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    dimensions.times do |i|
      @position[i] += @velocity[i]
      @position[i] = [@position[i], -10.0].max
      @position[i] = [@position[i], 10.0].min
    end
  end

  def evaluate(objective_function)
    @best_score = objective_function(@position)
    if @best_score < @best_score
      @best_position = @position.dup
    end
  end
end

def objective_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def main
  swarm_size = 30
  dimensions = 2
  swarm = Swarm.new(swarm_size, dimensions)
  100.times do
    swarm.update_global_best
    swarm.particles.each do |particle|
      particle.evaluate(method(:objective_function))
    end
    swarm.update_particles
  end
  puts "#{swarm.global_best.best_score} #{swarm.global_best.best_position.inspect}"
end

main if __FILE__ == $0