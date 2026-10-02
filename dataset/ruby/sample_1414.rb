require 'matrix'

class Swarm
  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @positions = Array.new(size) { Array.new(dimensions) { rand } }
    @velocities = Array.new(size) { Array.new(dimensions) { rand } }
    @best_positions = @positions.map(&:dup)
    @best_score = Float::INFINITY
  end

  def update_personal_best(score)
    if score < @best_score
      @best_score = score
      @best_positions = @positions.map(&:dup)
    end
  end

  def update_velocity(global_best)
    inertia = 0.5
    cognitive = 1.5
    social = 1.5
    @velocities.each_with_index do |velocity, i|
      velocity.each_with_index do |v, j|
        r1, r2 = rand, rand
        velocity[j] = inertia * v + cognitive * r1 * (@best_positions[i][j] - @positions[i][j]) + social * r2 * (global_best[j] - @positions[i][j])
      end
    end
  end

  def update_position
    @positions.each_with_index do |position, i|
      position.each_with_index do |p, j|
        position[j] += @velocities[i][j]
      end
    end
  end
end

class Environment
  def initialize(swarm)
    @swarm = swarm
  end

  def evaluate
    scores = @swarm.positions.map { |position| position.map { |x| x ** 2 }.sum }
  end

  def find_global_best(scores)
    global_best_index = scores.index(scores.min)
    @swarm.positions[global_best_index]
  end
end

def main
  swarm = Swarm.new(size: 10, dimensions: 3)
  environment = Environment.new(swarm)
  iterations = 50
  iterations.times do
    scores = environment.evaluate
    global_best = environment.find_global_best(scores)
    swarm.update_personal_best(scores.min)
    swarm.update_velocity(global_best)
    swarm.update_position
  end
  puts "Best score: #{swarm.best_score}"
end

main if __FILE__ == $0