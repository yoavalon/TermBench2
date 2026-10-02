require 'random'

class Particle
  def initialize(dimensions, lower_bound, upper_bound)
    @position = Array.new(dimensions) { Random.uniform(lower_bound, upper_bound) }
    @velocity = Array.new(dimensions) { Random.uniform(-1, 1) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end

  def update_velocity(global_best_position, w, c1, c2)
    @position.each_index do |i|
      r1, r2 = Random.random, Random.random
      cognitive_velocity = c1 * r1 * (@best_position[i] - @position[i])
      social_velocity = c2 * r2 * (global_best_position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive_velocity + social_velocity
    end
  end

  def update_position(lower_bound, upper_bound)
    @position.each_index do |i|
      @position[i] += @velocity[i]
      @position[i] = [lower_bound, [@position[i], upper_bound].min].max
    end
  end
end

class Swarm
  def initialize(num_particles, dimensions, lower_bound, upper_bound)
    @particles = Array.new(num_particles) { Particle.new(dimensions, lower_bound, upper_bound) }
    @global_best_position = Array.new(dimensions) { Random.uniform(lower_bound, upper_bound) }
    @global_best_fitness = Float::INFINITY
  end

  def evaluate_fitness(objective_function)
    @particles.each do |particle|
      fitness = objective_function(particle.position)
      if fitness < particle.best_fitness
        particle.best_fitness = fitness
        particle.best_position = particle.position.dup
      end
      if fitness < @global_best_fitness
        @global_best_fitness = fitness
        @global_best_position = particle.position.dup
      end
    end
  end

  def update_particles(w, c1, c2)
    @particles.each do |particle|
      particle.update_velocity(@global_best_position, w, c1, c2)
      particle.update_position(-10, 10)
    end
  end
end

def objective_function(x)
  x.map.with_index { |xi, i| Math.sin(xi) * Math.sin(xi + (i + 1) * Math::PI / x.length) }.sum
end

def main
  num_particles = 30
  dimensions = 30
  lower_bound = -10
  upper_bound = 10
  w = 0.729
  c1 = 1.494
  c2 = 1.494
  swarm = Swarm.new(num_particles, dimensions, lower_bound, upper_bound)
  loop do
    swarm.evaluate_fitness(method(:objective_function))
    swarm.update_particles(w, c1, c2)
  end
end

main