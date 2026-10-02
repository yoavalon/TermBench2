require 'random'

class Particle
  attr_accessor :position, :velocity, :best_position, :best_score

  def initialize(dimensions, lower_bound, upper_bound)
    @position = Array.new(dimensions) { rand(lower_bound..upper_bound) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best_position, w, c1, c2)
    @velocity.each_index do |i|
      r1, r2 = rand, rand
      @velocity[i] = w * @velocity[i] + c1 * r1 * (@best_position[i] - @position[i]) + c2 * r2 * (global_best_position[i] - @position[i])
    end
  end

  def update_position
    @velocity.each_index do |i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate(fitness_function)
    @best_score = [@best_score, fitness_function.call(@position)].min
    if @best_score < fitness_function.call(@position)
      @best_position = @position.dup
    end
  end
end

class Swarm
  attr_accessor :particles, :global_best_position, :global_best_score

  def initialize(size, dimensions, lower_bound, upper_bound)
    @particles = Array.new(size) { Particle.new(dimensions, lower_bound, upper_bound) }
    @global_best_position = Array.new(dimensions) { rand(lower_bound..upper_bound) }
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

  def iterate(fitness_function, w, c1, c2)
    @particles.each do |particle|
      particle.update_velocity(@global_best_position, w, c1, c2)
      particle.update_position
      particle.evaluate(fitness_function)
    end
    update_global_best
  end
end

def fitness_function(position)
  position.map { |x| x ** 2 }.sum
end

def main
  dimensions = 2
  lower_bound = -10
  upper_bound = 10
  swarm_size = 30
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  iterations = 100
  swarm = Swarm.new(swarm_size, dimensions, lower_bound, upper_bound)
  iterations.times do
    swarm.iterate(method(:fitness_function), w, c1, c2)
  end
  puts "Global best score: #{swarm.global_best_score}"
  puts "Global best position: #{swarm.global_best_position}"
end

main