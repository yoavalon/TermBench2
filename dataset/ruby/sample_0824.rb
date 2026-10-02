class Particle
  attr_accessor :position, :velocity, :best_position, :best_fitness

  def initialize(dimensions, max_velocity)
    @position = Array.new(dimensions, 0.0)
    @velocity = Array.new(dimensions, 0.0)
    @best_position = Array.new(dimensions, 0.0)
    @max_velocity = max_velocity
    @best_fitness = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    dimensions = @position.length
    dimensions.times do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
      @velocity[i] = [@velocity[i], -@max_velocity].max
      @velocity[i] = [@velocity[i], @max_velocity].min
    end
  end

  def update_position
    dimensions = @position.length
    dimensions.times do |i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate(objective_function)
    @fitness = objective_function.call(@position)
    if @fitness < @best_fitness
      @best_fitness = @fitness
      @best_position = @position.dup
    end
  end
end

class Swarm
  attr_accessor :particles, :global_best, :global_best_fitness

  def initialize(dimensions, population_size, max_velocity)
    @particles = Array.new(population_size) { Particle.new(dimensions, max_velocity) }
    @global_best = Array.new(dimensions, 0.0)
    @global_best_fitness = Float::INFINITY
  end

  def initialize_global_best
    @particles.each do |particle|
      particle.evaluate(method(:objective_function))
      if particle.best_fitness < @global_best_fitness
        @global_best_fitness = particle.best_fitness
        @global_best = particle.best_position.dup
      end
    end
  end

  def update_swarm(w, c1, c2)
    @particles.each do |particle|
      particle.update_velocity(@global_best, w, c1, c2)
      particle.update_position
      particle.evaluate(method(:objective_function))
      if particle.best_fitness < @global_best_fitness
        @global_best_fitness = particle.best_fitness
        @global_best = particle.best_position.dup
      end
    end
  end
end

def objective_function(position)
  position.sum { |x| x ** 2 }
end

def optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations)
  swarm = Swarm.new(dimensions, population_size, max_velocity)
  swarm.initialize_global_best
  max_iterations.times do
    swarm.update_swarm(w, c1, c2)
  end
  swarm.global_best_fitness
end

def main
  dimensions = 2
  population_size = 30
  max_velocity = 0.1
  w = 0.729
  c1 = 1.494
  c2 = 1.494
  max_iterations = 100
  best_fitness = optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations)
  puts "Best Fitness: #{best_fitness}"
end

main