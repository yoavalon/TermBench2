require 'random'

class Swarm
  attr_accessor :size, :dimensions, :bounds, :positions, :velocities, :pbest_positions, :pbest_scores, :gbest_position, :gbest_score

  def initialize(size, dimensions, bounds)
    @size = size
    @dimensions = dimensions
    @bounds = bounds
    @positions = Array.new(size) { Array.new(dimensions, 0.0) }
    @velocities = Array.new(size) { Array.new(dimensions, 0.0) }
    @pbest_positions = Array.new(size) { Array.new(dimensions, 0.0) }
    @pbest_scores = Array.new(size, Float::INFINITY)
    @gbest_position = Array.new(dimensions, 0.0)
    @gbest_score = Float::INFINITY
  end

  def initialize
    @size.times do |i|
      @dimensions.times do |j|
        @positions[i][j] = (@bounds[j][1] - @bounds[j][0]) * Random.rand + @bounds[j][0]
        @velocities[i][j] = (@bounds[j][1] - @bounds[j][0]) * Random.rand - (@bounds[j][1] - @bounds[j][0]) / 2
      end
    end
  end

  def evaluate(function)
    @size.times do |i|
      score = function.call(@positions[i])
      if score < @pbest_scores[i]
        @pbest_scores[i] = score
        @pbest_positions[i] = @positions[i].dup
      end
      if score < @gbest_score
        @gbest_score = score
        @gbest_position = @positions[i].dup
      end
    end
  end

  def update_velocities(w, c1, c2)
    @size.times do |i|
      @dimensions.times do |j|
        @velocities[i][j] = w * @velocities[i][j] + c1 * Random.rand * (@pbest_positions[i][j] - @positions[i][j]) + c2 * Random.rand * (@gbest_position[j] - @positions[i][j])
      end
    end
  end

  def update_positions
    @size.times do |i|
      @dimensions.times do |j|
        @positions[i][j] += @velocities[i][j]
        @positions[i][j] = [@bounds[j][0], [@bounds[j][1], @positions[i][j]].min].max
      end
    end
  end

  def optimize(function, iterations)
    initialize
    iterations.times do
      evaluate(function)
      update_velocities(0.7, 1.5, 1.5)
      update_positions
    end
    @gbest_score
  end
end

def objective(x)
  x.map { |xi| (xi - 0.5) ** 2 }.sum
end

def main
  dimensions = 3
  bounds = [(-10, 10)] * dimensions
  swarm_size = 30
  iterations = 100
  swarm = Swarm.new(swarm_size, dimensions, bounds)
  best_score = swarm.optimize(method(:objective), iterations)
  puts best_score
end

main if __FILE__ == $0