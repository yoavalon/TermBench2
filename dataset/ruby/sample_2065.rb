require 'random'

class Particle
  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0..10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best_position, w, c1, c2)
    @velocity.each_with_index do |_, i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best_position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    @position.each_with_index do |_, i|
      @position[i] += @velocity[i]
      @position[i] = -10 if @position[i] < -10
      @position[i] = 10 if @position[i] > 10
    end
  end

  def evaluate(objective_function)
    score = objective_function.call(@position)
    if score < @best_score
      @best_score = score
      @best_position = @position.dup
    end
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

  def optimize(objective_function, w, c1, c2, iterations)
    iterations.times do
      @particles.each do |particle|
        particle.update_velocity(@global_best_position, w, c1, c2)
        particle.update_position
        particle.evaluate(objective_function)
      end
      update_global_best
    end
  end
end

def objective_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def main
  dimensions = 3
  num_particles = 10
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  iterations = 50
  swarm = Swarm.new(num_particles, dimensions)
  swarm.optimize(method(:objective_function), w, c1, c2, iterations)
  puts "Best position: #{@global_best_position}"
  puts "Best score: #{@global_best_score}"
end

main if __FILE__ == $0