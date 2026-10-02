require 'random'

class Swarm

  def initialize(size, dimensions, search_space)
    @size = size
    @dimensions = dimensions
    @search_space = search_space
    @particles = Array.new(size) { Particle.new(dimensions, search_space) }
  end

  def update
    @particles.each do |particle|
      particle.update_velocity
      particle.update_position
    end
  end
end

class Particle

  def initialize(dimensions, search_space)
    @dimensions = dimensions
    @search_space = search_space
    @position = Array.new(dimensions) { Random.rand(search_space[0]..search_space[1]) }
    @velocity = Array.new(dimensions) { Random.rand(-1..1) }
    @best_position = @position.dup
    @best_fitness = Float::INFINITY
  end

  def update_velocity
    w = 0.7
    c1 = 1.5
    c2 = 1.5
    @dimensions.times do |i|
      r1, r2 = Random.rand, Random.rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (@best_position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    @dimensions.times do |i|
      @position[i] += @velocity[i]
      @position[i] = [@search_space[0], [@search_space[1], @position[i]].min].max
    end
  end
end

def fitness_function(position)
  position.map { |x| x ** 2 }.sum
end

def optimize(swarm, max_iterations)
  max_iterations.times do |iteration|
    swarm.particles.each do |particle|
      current_fitness = fitness_function(particle.position)
      if current_fitness < particle.best_fitness
        particle.best_fitness = current_fitness
        particle.best_position = particle.position.dup
      end
    end
    swarm.update
  end
end

def main
  size = 30
  dimensions = 2
  search_space = [-10, 10]
  max_iterations = 100
  swarm = Swarm.new(size, dimensions, search_space)
  optimize(swarm, max_iterations)
end

main if __FILE__ == $0