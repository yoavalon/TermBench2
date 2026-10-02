require 'securerandom'

class Particle

  def initialize(dim)
    @position = Array.new(dim) { SecureRandom.random_number * 20 - 10 }
    @velocity = Array.new(dim) { SecureRandom.random_number * 2 - 1 }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end

  def update_velocity(global_best, w=0.5, c1=1.5, c2=1.5)
    dim = @position.length
    dim.times do |i|
      r1, r2 = SecureRandom.random_number, SecureRandom.random_number
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    dim = @position.length
    dim.times do |i|
      @position[i] += @velocity[i]
    end
  end

end

class Swarm

  def initialize(dim, num_particles)
    @particles = Array.new(num_particles) { Particle.new(dim) }
    @global_best_position = Array.new(dim) { Float::INFINITY }
    @global_best_fitness = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      fitness = evaluate(particle.position)
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

  def evaluate(position)
    position.map { |x| x ** 2 }.sum
  end

  def iterate
    update_global_best
    @particles.each do |particle|
      particle.update_velocity(@global_best_position)
      particle.update_position
    end
  end

end

def main
  dim = 2
  num_particles = 10
  swarm = Swarm.new(dim, num_particles)
  loop do
    swarm.iterate
  end
end

main