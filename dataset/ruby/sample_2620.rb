class Swarm
  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @positions = Array.new(size) { Array.new(dimensions, 0.0) }
    @velocities = Array.new(size) { Array.new(dimensions, 0.0) }
    @best_positions = Array.new(size) { Array.new(dimensions, 0.0) }
    @best_scores = Array.new(size) { Float::INFINITY }
  end

  def update_best_positions(scores)
    @size.times do |i|
      if scores[i] < @best_scores[i]
        @best_scores[i] = scores[i]
        @best_positions[i] = @positions[i].dup
      end
    end
  end

  def update_velocities(global_best_position, w: 0.7, c1: 1.5, c2: 1.5)
    @size.times do |i|
      @dimensions.times do |j|
        r1, r2 = 0.5, 0.5
        @velocities[i][j] = w * @velocities[i][j] + c1 * r1 * (@best_positions[i][j] - @positions[i][j]) + c2 * r2 * (global_best_position[j] - @positions[i][j])
      end
    end
  end

  def update_positions
    @size.times do |i|
      @dimensions.times do |j|
        @positions[i][j] += @velocities[i][j]
      end
    end
  end
end

def fitness_function(position)
  position.map { |x| x ** 2 }.sum
end

def main
  swarm_size = 30
  dimensions = 2
  max_iterations = 100
  swarm = Swarm.new(swarm_size, dimensions)
  max_iterations.times do
    scores = swarm.positions.map { |position| fitness_function(position) }
    global_best_index = scores.index(scores.min)
    global_best_position = swarm.positions[global_best_index]
    swarm.update_best_positions(scores)
    swarm.update_velocities(global_best_position)
    swarm.update_positions
  end
  best_score = scores.min
  best_position = swarm.positions[scores.index(best_score)]
  puts "Best score: #{best_score}"
  puts "Best position: #{best_position}"
end

main if __FILE__ == $0