require 'matrix'

class Swarm

  def initialize(size, dimensions, bounds)
    @size = size
    @dimensions = dimensions
    @bounds = bounds
    @particles = Array.new(size) { Particle.new(dimensions, bounds) }
    @gbest = nil
  end

  def update_gbest
    @particles.each do |particle|
      @gbest = particle if @gbest.nil? || particle.fitness < @gbest.fitness
    end
  end

  def update_particles
    @particles.each do |particle|
      particle.update_velocity(@gbest)
      particle.update_position
    end
  end
end

class Particle

  def initialize(dimensions, bounds)
    @position = Array.new(dimensions) { rand(bounds[0]..bounds[1]) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @fitness = Float::INFINITY
  end

  def update_velocity(gbest)
    w, c1, c2 = 0.5, 1.5, 1.5
    @velocity.each_with_index do |_, i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (gbest.position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    @position.each_with_index do |_, i|
      @position[i] += @velocity[i]
      @position[i] = [@bounds[0], [@position[i], @bounds[1]].min].max
    end
  end
end

def objective_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def optimize(swarm, max_iterations)
  max_iterations.times do
    swarm.update_gbest
    swarm.particles.each do |particle|
      particle.fitness = objective_function(particle.position)
    end
    swarm.update_particles
  end
end

def main
  size = 30
  dimensions = 2
  bounds = [-10, 10]
  max_iterations = 100
  swarm = Swarm.new(size, dimensions, bounds)
  optimize(swarm, max_iterations)
  puts swarm.gbest.position.inspect
end

main if __FILE__ == $0