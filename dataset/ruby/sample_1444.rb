require 'random'

class Particle
  def initialize(dimensions, bounds)
    @position = Array.new(dimensions) { Random.uniform(bounds[0], bounds[1]) }
    @velocity = Array.new(dimensions) { Random.uniform(-1, 1) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, w: 0.7, c1: 1.5, c2: 1.5)
    (0...@velocity.length).each do |i|
      r1, r2 = Random.random, Random.random
      @velocity[i] = w * @velocity[i] + c1 * r1 * (@best_position[i] - @position[i]) + c2 * r2 * (global_best[i] - @position[i])
    end
  end

  def update_position(bounds)
    (0...@position.length).each do |i|
      @position[i] += @velocity[i]
      @position[i] = [bounds[0], [@position[i], bounds[1]].min].max
    end
  end

  def evaluate(objective_function)
    score = objective_function.call(@position)
    if score < @best_score
      @best_score = score
      @best_position = @position.dup
    end
  end
end

class Swarm
  def initialize(num_particles, dimensions, bounds)
    @particles = Array.new(num_particles) { Particle.new(dimensions, bounds) }
    @global_best_position = @particles[0].best_position.dup
    @global_best_score = @particles[0].best_score
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_score < @global_best_score
        @global_best_score = particle.best_score
        @global_best_position = particle.best_position.dup
      end
    end
  end

  def iterate(objective_function)
    @particles.each do |particle|
      particle.update_velocity(@global_best_position)
      particle.update_position(objective_function.bounds)
      particle.evaluate(objective_function)
    end
    update_global_best
  end
end

class ObjectiveFunction
  attr_accessor :bounds

  def initialize(bounds)
    @bounds = bounds
  end

  def call(position)
    x, y = position
    (x ** 2 + y - 11) ** 2 + (x + y ** 2 - 7) ** 2
  end
end

def main
  dimensions = 2
  num_particles = 30
  bounds = [-5, 5]
  objective_function = ObjectiveFunction.new(bounds)
  swarm = Swarm.new(num_particles, dimensions, bounds)
  100.times do
    swarm.iterate(objective_function)
    break if swarm.global_best_score < 1e-06
  end
  puts "Best position: #{swarm.global_best_position}"
  puts "Best score: #{swarm.global_best_score}"
end

main if __FILE__ == $0