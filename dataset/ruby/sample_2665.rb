require 'random'

class Particle

  def initialize(dimensions, bounds)
    @position = bounds.map { |b| rand(b[0]..b[1]) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    @position.length.times do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position(bounds)
    @position.length.times do |i|
      @position[i] += @velocity[i]
      @position[i] = [bounds[i][0], [@position[i], bounds[i][1]].min].max
    end
  end

  def evaluate(fitness_function)
    @best_fitness = [@best_fitness, fitness_function.call(@position)].min
  end
end

def optimize(fitness_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations)
  particles = Array.new(num_particles) { Particle.new(dimensions, bounds) }
  global_best = Array.new(dimensions, Float::INFINITY)
  global_best_fitness = Float::INFINITY
  max_iterations.times do
    particles.each do |particle|
      particle.evaluate(fitness_function)
      if particle.best_fitness < global_best_fitness
        global_best_fitness = particle.best_fitness
        global_best = particle.best_position.dup
      end
    end
    particles.each do |particle|
      particle.update_velocity(global_best, w, c1, c2)
      particle.update_position(bounds)
    end
  end
  [global_best, global_best_fitness]
end

def main
  sphere_function = ->(x) { x.map { |xi| xi ** 2 }.sum }
  dimensions = 3
  bounds = Array.new(dimensions) { [-5.12, 5.12] }
  num_particles = 30
  w = 0.729
  c1 = 1.494
  c2 = 1.494
  max_iterations = 100
  best_position, best_fitness = optimize(sphere_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations)
  puts 'Best position:', best_position
  puts 'Best fitness:', best_fitness
end

main