require 'matrix'

class PSOSettings
  attr_accessor :dimensions, :population_size, :max_iterations, :c1, :c2, :w

  def initialize(dimensions, population_size, max_iterations)
    @dimensions = dimensions
    @population_size = population_size
    @max_iterations = max_iterations
    @c1 = 2.0
    @c2 = 2.0
    @w = 0.7
  end
end

class Particle
  attr_accessor :position, :velocity, :best_position, :best_fitness

  def initialize(dimensions, lower_bound, upper_bound)
    @position = Array.new(dimensions) { rand(lower_bound..upper_bound) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end
end

def fitness(position)
  position.map { |x| x ** 2 }.sum
end

def update_velocity(particle, global_best, settings)
  settings.dimensions.times do |i|
    r1, r2 = rand, rand
    cognitive = settings.c1 * r1 * (particle.best_position[i] - particle.position[i])
    social = settings.c2 * r2 * (global_best[i] - particle.position[i])
    particle.velocity[i] = settings.w * particle.velocity[i] + cognitive + social
  end
end

def update_position(particle, settings)
  settings.dimensions.times do |i|
    particle.position[i] += particle.velocity[i]
    particle.position[i] = [particle.position[i], -10].max
    particle.position[i] = [particle.position[i], 10].min
  end
end

def optimize(settings)
  population = Array.new(settings.population_size) { Particle.new(settings.dimensions, -10, 10) }
  global_best = Array.new(settings.dimensions, 0)
  global_best_fitness = Float::INFINITY
  settings.max_iterations.times do |iteration|
    population.each do |particle|
      current_fitness = fitness(particle.position)
      if current_fitness < particle.best_fitness
        particle.best_fitness = current_fitness
        particle.best_position = particle.position.dup
      end
      if current_fitness < global_best_fitness
        global_best_fitness = current_fitness
        global_best = particle.position.dup
      end
    end
    population.each do |particle|
      update_velocity(particle, global_best, settings)
      update_position(particle, settings)
    end
  end
  [global_best, global_best_fitness]
end

def main
  settings = PSOSettings.new(dimensions: 2, population_size: 30, max_iterations: 100)
  best_position, best_fitness = optimize(settings)
  puts "Best position: #{best_position}"
  puts "Best fitness: #{best_fitness}"
end

main