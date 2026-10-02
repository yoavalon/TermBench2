require 'random'

class Particle
  def initialize(dimensions)
    @position = Array.new(dimensions) { rand(-10.0..10.0) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end
end

class Swarm
  def initialize(num_particles, dimensions)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best_position = Array.new(dimensions, 0.0)
    @global_best_score = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      score = evaluate(particle.position)
      if score < @global_best_score
        @global_best_score = score
        @global_best_position = particle.position.dup
      end
    end
  end

  def evaluate(position)
    position.map { |x| x ** 2 }.sum
  end

  def update_particles(w, c1, c2)
    @particles.each do |particle|
      particle.position.each_with_index do |_, i|
        r1, r2 = rand, rand
        particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (global_best_position[i] - particle.position[i])
        particle.position[i] += particle.velocity[i]
        particle.best_score = [@best_score, evaluate(particle.position)].min
        particle.best_position = particle.position.dup if particle.best_score < evaluate(particle.best_position)
      end
    end
  end
end

def main
  dimensions = 30
  num_particles = 30
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  iterations = 100
  swarm = Swarm.new(num_particles, dimensions)
  iterations.times do
    swarm.update_global_best
    swarm.update_particles(w, c1, c2)
  end
  puts "Best score: #{swarm.global_best_score}"
end

main if __FILE__ == $0