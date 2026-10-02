require 'random'

class Particle

  def initialize(dimensions, position = nil)
    @position = position || Array.new(dimensions) { rand(-1.0..1.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, w = 0.7, c1 = 1.5, c2 = 1.5)
    dimensions = @position.length
    dimensions.times do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position(bounds)
    dimensions = @position.length
    dimensions.times do |i|
      @position[i] += @velocity[i]
      if bounds
        @position[i] = [bounds[0], [@position[i], bounds[1]].max].max
      end
    end
  end

  def evaluate(function)
    @current_score = function.call(@position)
    if @current_score < @best_score
      @best_score = @current_score
      @best_position = @position.dup
    end
  end
end

class Swarm

  def initialize(dimensions, num_particles, bounds = nil)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best = nil
    @global_best_score = Float::INFINITY
    @bounds = bounds
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_score < @global_best_score
        @global_best_score = particle.best_score
        @global_best = particle.best_position.dup
      end
    end
  end

  def optimize(function, iterations)
    iterations.times do
      update_global_best
      @particles.each do |particle|
        particle.update_velocity(@global_best)
        particle.update_position(@bounds)
        particle.evaluate(function)
      end
    end
  end
end

def objective_function(x)
  x.sum { |xi| xi ** 2 }
end

def main
  dimensions = 2
  num_particles = 30
  bounds = [-10, 10]
  iterations = 100
  swarm = Swarm.new(dimensions, num_particles, bounds)
  swarm.optimize(method(:objective_function), iterations)
  puts "Global Best Position: #{@global_best.inspect}"
  puts "Global Best Score: #{@global_best_score}"
end

main if __FILE__ == $0