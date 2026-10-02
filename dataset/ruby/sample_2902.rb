require 'random'

class Particle

  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-1.0..1.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    @position.size.times do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position(bounds)
    @position.size.times do |i|
      @position[i] += @velocity[i]
      @position[i] = [bounds[0][i], [@position[i], bounds[1][i]].min].max
    end
  end

  def evaluate_fitness(fitness_function)
    @fitness = fitness_function.call(@position)
    if @fitness < @best_fitness
      @best_fitness = @fitness
      @best_position = @position.dup
    end
  end
end

class Swarm

  def initialize(num_particles, dimensions, bounds, fitness_function)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best = Array.new(dimensions) { rand(-1.0..1.0) }
    @global_best_fitness = Float::INFINITY
    @fitness_function = fitness_function
    @bounds = bounds
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_fitness < @global_best_fitness
        @global_best_fitness = particle.best_fitness
        @global_best = particle.best_position.dup
      end
    end
  end

  def optimize(w, c1, c2)
    loop do
      @particles.each do |particle|
        particle.update_velocity(@global_best, w, c1, c2)
        particle.update_position(@bounds)
        particle.evaluate_fitness(@fitness_function)
      end
      update_global_best
    end
  end
end

def fitness_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def main
  dimensions = 2
  num_particles = 30
  bounds = [[-10, -10], [10, 10]]
  swarm = Swarm.new(num_particles, dimensions, bounds, method(:fitness_function))
  w = 0.729
  c1 = 1.494
  c2 = 1.494
  swarm.optimize(w, c1, c2)
end

main