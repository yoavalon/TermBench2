require 'random'

class Swarm
  def initialize(size, dimensions, search_space)
    @size = size
    @dimensions = dimensions
    @search_space = search_space
    @particles = Array.new(size) { Particle.new(dimensions, search_space) }
    @best_position = @particles.sample.position
    @best_score = Float::INFINITY
  end

  def update_best_position
    @particles.each do |particle|
      if particle.score < @best_score
        @best_score = particle.score
        @best_position = particle.position.dup
      end
    end
  end

  def iterate
    @particles.each do |particle|
      particle.update_velocity(@best_position)
      particle.move
      particle.evaluate
    end
  end

  def run(iterations)
    iterations.times do
      iterate
      update_best_position
    end
  end
end

class Particle
  def initialize(dimensions, search_space)
    @position = Array.new(dimensions) { rand(search_space[0]..search_space[1]) }
    @velocity = Array.new(dimensions, 0.0)
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best)
    inertia = 0.5
    cognitive_factor = 1.5
    social_factor = 1.5
    @position.each_index do |i|
      r1, r2 = rand, rand
      cognitive = cognitive_factor * r1 * (@best_position[i] - @position[i])
      social = social_factor * r2 * (global_best[i] - @position[i])
      @velocity[i] = inertia * @velocity[i] + cognitive + social
    end
  end

  def move
    @position.each_index do |i|
      @position[i] += @velocity[i]
    end
  end

  def evaluate
    @score = objective_function
    if @score < @best_score
      @best_score = @score
      @best_position = @position.dup
    end
  end

  def objective_function
    @position.sum { |x| x ** 2 }
  end
end

def main
  swarm_size = 30
  dimensions = 2
  search_space = [-10, 10]
  iterations = 100
  swarm = Swarm.new(swarm_size, dimensions, search_space)
  swarm.run(iterations)
  puts "Best position: #{swarm.best_position}"
  puts "Best score: #{swarm.best_score}"
end

main if __FILE__ == $0