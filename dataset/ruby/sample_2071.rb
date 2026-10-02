require 'random'

class Particle

  def initialize(dim, bounds)
    @position = bounds.map { |b| Random.uniform(b[0], b[1]) }
    @velocity = Array.new(dim) { Random.uniform(-1, 1) }
    @best_pos = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, w=0.7, c1=1.5, c2=1.5)
    @position.length.times do |i|
      r1, r2 = Random.random, Random.random
      cognitive = c1 * r1 * (@best_pos[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position(bounds)
    @position.length.times do |i|
      @position[i] += @velocity[i]
      @position[i] = [bounds[i][0], [@position[i], bounds[i][1]].min].max
    end
  end
end

class Swarm

  def initialize(dim, num_particles, bounds)
    @particles = Array.new(num_particles) { Particle.new(dim, bounds) }
    @global_best = Array.new(dim) { Float::INFINITY }
    @global_best_score = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      score = evaluate(particle.position)
      if score < @global_best_score
        @global_best = particle.position.dup
        @global_best_score = score
        particle.best_score = score
        particle.best_pos = particle.position.dup
      end
    end
  end

  def evaluate(position)
    position.map { |x| x ** 2 }.sum
  end

  def run(iterations)
    iterations.times do
      @particles.each do |particle|
        particle.update_velocity(@global_best)
        particle.update_position(@bound)
      end
      update_global_best
    end
  end
end

def main
  dim = 3
  num_particles = 20
  bounds = Array.new(dim) { [-10, 10] }
  swarm = Swarm.new(dim, num_particles, bounds)
  swarm.run(100)
  puts "Global Best Position: #{swarm.global_best}"
  puts "Global Best Score: #{swarm.global_best_score}"
end

main