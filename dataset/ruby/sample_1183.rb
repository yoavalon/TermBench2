class Swarm

  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @positions = Array.new(size) { Array.new(dimensions, 0.0) }
    @velocities = Array.new(size) { Array.new(dimensions, 0.0) }
    @best_positions = Array.new(size) { Array.new(dimensions, 0.0) }
    @best_scores = Array.new(size, Float::INFINITY)
    @global_best_position = Array.new(dimensions, 0.0)
    @global_best_score = Float::INFINITY
  end

  def update_global_best
    @size.times do |i|
      score = evaluate(@best_positions[i])
      if score < @global_best_score
        @global_best_score = score
        @global_best_position = @best_positions[i].dup
      end
    end
  end

  def evaluate(position)
    position.map { |x| x ** 2 }.sum
  end

  def update_particles
    @size.times do |i|
      @dimensions.times do |j|
        r1, r2 = 0.5, 0.5
        c1, c2 = 2.0, 2.0
        @velocities[i][j] = 0.7 * @velocities[i][j] + c1 * r1 * (@best_positions[i][j] - @positions[i][j]) + c2 * r2 * (@global_best_position[j] - @positions[i][j])
        @positions[i][j] += @velocities[i][j]
      end
      @best_scores[i] = evaluate(@positions[i])
      if @best_scores[i] < @global_best_score
        @best_positions[i] = @positions[i].dup
      end
    end
  end

  def iterate
    update_global_best
    update_particles
    iterate
  end
end

def main
  swarm = Swarm.new(30, 2)
  swarm.iterate
end

main