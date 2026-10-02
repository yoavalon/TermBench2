require 'matrix'

class Particle
  attr_accessor :position, :velocity, :best_position, :best_score

  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0..10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end
end

class Swarm
  attr_accessor :particles, :gbest_position, :gbest_score

  def initialize(num_particles, dimensions)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @gbest_position = nil
    @gbest_score = Float::INFINITY
  end

  def update_gbest
    @particles.each do |particle|
      if particle.best_score < @gbest_score
        @gbest_score = particle.best_score
        @gbest_position = particle.best_position.dup
      end
    end
  end

  def update_particles(w, c1, c2)
    @particles.each do |particle|
      particle.position.zip(particle.velocity, particle.best_position, @gbest_position).each_with_index do |(xi, vi, pbest_i, gbest_i), i|
        r1, r2 = rand, rand
        particle.velocity[i] = w * vi + c1 * r1 * (pbest_i - xi) + c2 * r2 * (gbest_i - xi)
        particle.position[i] += particle.velocity[i]
      end
    end
  end

  def evaluate(objective_function)
    @particles.each do |particle|
      score = objective_function.call(particle.position)
      if score < particle.best_score
        particle.best_score = score
        particle.best_position = particle.position.dup
      end
    end
  end
end

def objective_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def main
  dimensions = 3
  num_particles = 20
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  iterations = 100
  swarm = Swarm.new(num_particles, dimensions)
  iterations.times do
    swarm.update_gbest
    swarm.update_particles(w, c1, c2)
    swarm.evaluate(method(:objective_function))
  end
  puts "Best score: #{swarm.gbest_score}"
  puts "Best position: #{swarm.gbest_position}"
end

main if __FILE__ == $0