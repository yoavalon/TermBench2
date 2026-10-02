require 'random'

class Particle
  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0..10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best_position, w, c1, c2)
    @position.each_with_index do |_, i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best_position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    @position.each_with_index do |_, i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate(fitness_function)
    @best_score = fitness_function.call(@position)
    @best_score
  end
end

class Swarm
  def initialize(num_particles, dimensions)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best_position = Array.new(dimensions) { rand(-10.0..10.0) }
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
end

def fitness_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def optimize(swarm, w, c1, c2, iterations)
  iterations.times do
    swarm.particles.each do |particle|
      particle.update_velocity(swarm.global_best_position, w, c1, c2)
      particle.update_position
      particle.evaluate(method(:fitness_function))
    end
    swarm.update_global_best
  end
  [swarm.global_best_position, swarm.global_best_score]
end

def main
  dimensions = 10
  num_particles = 20
  w = 0.7
  c1 = 2.0
  c2 = 2.0
  iterations = 100
  swarm = Swarm.new(num_particles, dimensions)
  best_position, best_score = optimize(swarm, w, c1, c2, iterations)
  puts "Best position: #{best_position}"
  puts "Best score: #{best_score}"
end

main