require 'matrix'

class Particle
  attr_accessor :position, :velocity, :best_position, :best_fitness

  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0...10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0...1.0) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    dimensions = @velocity.length
    (0...dimensions).each do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    dimensions = @position.length
    (0...dimensions).each do |i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate_fitness(fitness_function)
    @best_fitness = fitness_function.call(@position)
    if @best_fitness < fitness_function.call(@best_position)
      @best_position = @position.dup
    end
  end
end

class Swarm
  attr_accessor :particles, :global_best_position, :global_best_fitness

  def initialize(dimensions, num_particles)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best_position = nil
    @global_best_fitness = Float::INFINITY
  end

  def update_global_best(fitness_function)
    @particles.each do |particle|
      particle.evaluate_fitness(fitness_function)
      if particle.best_fitness < @global_best_fitness
        @global_best_fitness = particle.best_fitness
        @global_best_position = particle.best_position.dup
      end
    end
  end

  def optimize(fitness_function, w, c1, c2, iterations)
    iterations.times do
      update_global_best(fitness_function)
      @particles.each do |particle|
        particle.update_velocity(@global_best_position, w, c1, c2)
        particle.update_position
      end
    end
  end
end

def sphere_function(x)
  x.sum { |xi| xi ** 2 }
end

def main
  dimensions = 3
  num_particles = 10
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  iterations = 100
  swarm = Swarm.new(dimensions, num_particles)
  swarm.optimize(method(:sphere_function), w, c1, c2, iterations)
  puts "Global Best Position: #{swarm.global_best_position}"
  puts "Global Best Fitness: #{swarm.global_best_fitness}"
end

main if __FILE__ == $0