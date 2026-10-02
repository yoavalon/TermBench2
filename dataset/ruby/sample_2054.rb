require 'random'

class Particle
  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-1.0...1.0) }
    @velocity = Array.new(dimensions) { rand(-1.0...1.0) }
    @best_position = @position.dup
    @best_value = Float::INFINITY
  end

  def update_velocity(global_best, w=0.7, c1=1.5, c2=1.5)
    (0...@position.length).each do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    (0...@position.length).each do |i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate(objective_function)
    @best_value = objective_function.call(@position)
    if @best_value < @best_value
      @best_position = @position.dup
    end
  end
end

class Swarm
  def initialize(dimensions, num_particles)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best = Array.new(dimensions) { Float::INFINITY }
    @global_best_value = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_value < @global_best_value
        @global_best_value = particle.best_value
        @global_best = particle.best_position.dup
      end
    end
  end

  def iterate(objective_function)
    @particles.each do |particle|
      particle.update_velocity(@global_best)
      particle.update_position
      particle.evaluate(objective_function)
    end
    update_global_best
  end
end

def objective_function(x)
  x.sum { |xi| xi ** 2 }
end

def optimize(dimensions, num_particles, max_iterations)
  swarm = Swarm.new(dimensions, num_particles)
  max_iterations.times do
    swarm.iterate(method(:objective_function))
  end
  swarm.global_best
end

def main
  dimensions = 10
  num_particles = 20
  max_iterations = 100
  best_solution = optimize(dimensions, num_particles, max_iterations)
  puts "Best solution: #{best_solution}"
end

main if __FILE__ == $0