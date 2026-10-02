require 'mathn'
require 'random'

class Particle

  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0..10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    dimensions = @position.length
    (0...dimensions).each do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    dimensions = @position.length
    (0...dimensions).each do |i|
      @position[i] += @velocity[i]
      @position[i] = -10.0 if @position[i] < -10.0
      @position[i] = 10.0 if @position[i] > 10.0
    end
  end

end

class Swarm

  def initialize(num_particles, dimensions)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best = Array.new(dimensions, Float::INFINITY)
    @global_best_score = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_score < @global_best_score
        @global_best = particle.best_position.dup
        @global_best_score = particle.best_score
      end
    end
  end

  def optimize(iterations, w, c1, c2)
    iterations.times do
      update_global_best
      @particles.each do |particle|
        particle.update_velocity(@global_best, w, c1, c2)
        particle.update_position
      end
    end
  end

end

def objective_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def main
  dimensions = 30
  num_particles = 30
  iterations = 100
  w = 0.7
  c1 = 2.0
  c2 = 2.0
  swarm = Swarm.new(num_particles, dimensions)
  swarm.particles.each do |particle|
    score = objective_function(particle.position)
    if score < particle.best_score
      particle.best_score = score
    end
  end
  swarm.optimize(iterations, w, c1, c2)
  best_score = swarm.global_best_score
  puts "Best Score: #{best_score}"
end

main if __FILE__ == $0