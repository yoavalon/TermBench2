require 'securerandom'

class Particle
  attr_accessor :position, :velocity, :best_position

  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0...10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0...1.0) }
    @best_position = @position.dup
  end

  def update_velocity(global_best, inertia, cognitive, social)
    @velocity.each_with_index do |_, i|
      r1, r2 = rand, rand
      @velocity[i] = inertia * @velocity[i] + cognitive * r1 * (@best_position[i] - @position[i]) + social * r2 * (global_best[i] - @position[i])
    end
  end

  def update_position
    @position.each_with_index do |_, i|
      @position[i] += @velocity[i]
    end
  end

  def update_best_position(objective_function)
    current_fitness = objective_function.call(@position)
    best_fitness = objective_function.call(@best_position)
    @best_position = @position.dup if current_fitness < best_fitness
  end
end

class Swarm
  attr_accessor :particles, :global_best, :objective_function

  def initialize(dimensions, num_particles, objective_function)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best = @particles[0].position.dup
    @objective_function = objective_function
  end

  def update_global_best
    @particles.each do |particle|
      current_fitness = @objective_function.call(particle.position)
      global_best_fitness = @objective_function.call(@global_best)
      @global_best = particle.position.dup if current_fitness < global_best_fitness
    end
  end

  def optimize(inertia, cognitive, social)
    loop do
      @particles.each do |particle|
        particle.update_velocity(@global_best, inertia, cognitive, social)
        particle.update_position
        particle.update_best_position(@objective_function)
      end
      update_global_best
    end
  end
end

def objective_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def main
  dimensions = 2
  num_particles = 30
  inertia = 0.7
  cognitive = 1.5
  social = 1.5
  swarm = Swarm.new(dimensions, num_particles, method(:objective_function))
  swarm.optimize(inertia, cognitive, social)
end

main