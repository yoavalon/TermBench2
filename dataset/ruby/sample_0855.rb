require 'matrix'

class Particle
  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-1.0..1.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, inertia, cognitive, social)
    @dimensions.times do |i|
      r1 = rand
      r2 = rand
      @velocity[i] = inertia * @velocity[i] + cognitive * r1 * (@best_position[i] - @position[i]) + social * r2 * (global_best[i] - @position[i])
    end
  end

  def update_position
    @dimensions.times do |i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate(fitness_function)
    @score = fitness_function.call(@position)
    if @score < @best_score
      @best_score = @score
      @best_position = @position.dup
    end
  end

  private

  attr_reader :dimensions
end

class Swarm
  def initialize(size, dimensions, fitness_function, max_iterations, inertia, cognitive, social)
    @particles = Array.new(size) { Particle.new(dimensions) }
    @fitness_function = fitness_function
    @max_iterations = max_iterations
    @inertia = inertia
    @cognitive = cognitive
    @social = social
    @global_best = nil
    @global_best_score = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_score < @global_best_score
        @global_best_score = particle.best_score
        @global_best = particle.best_position.dup
      end
    end
  end

  def optimize
    @max_iterations.times do
      @particles.each do |particle|
        particle.update_velocity(@global_best, @inertia, @cognitive, @social)
        particle.update_position
        particle.evaluate(@fitness_function)
      end
      update_global_best
    end
  end
end

def sphere_function(x)
  x.sum { |xi| xi ** 2 }
end

def main
  dimensions = 2
  size = 30
  max_iterations = 100
  inertia = 0.5
  cognitive = 1.5
  social = 1.5
  swarm = Swarm.new(size, dimensions, method(:sphere_function), max_iterations, inertia, cognitive, social)
  swarm.optimize
  puts "Best position: #{@global_best}"
  puts "Best score: #{@global_best_score}"
end

main if __FILE__ == $0