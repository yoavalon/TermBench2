class Swarm
  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @particles = Array.new(size) { Array.new(dimensions, 0.0) }
    @velocities = Array.new(size) { Array.new(dimensions, 0.0) }
    @best_positions = Array.new(size) { Array.new(dimensions, 0.0) }
    @best_scores = Array.new(size, Float::INFINITY)
    @global_best = Array.new(dimensions, 0.0)
    @global_best_score = Float::INFINITY
  end

  def update_global_best
    @size.times do |i|
      if @best_scores[i] < @global_best_score
        @global_best_score = @best_scores[i]
        @global_best = @best_positions[i].dup
      end
    end
  end

  def update_particles
    @size.times do |i|
      @dimensions.times do |j|
        r1, r2 = 0.5, 0.5
        cognitive = r1 * (@best_positions[i][j] - @particles[i][j])
        social = r2 * (@global_best[j] - @particles[i][j])
        @velocities[i][j] += cognitive + social
        @particles[i][j] += @velocities[i][j]
      end
    end
  end

  def evaluate(objective_function)
    @size.times do |i|
      score = objective_function.call(@particles[i])
      if score < @best_scores[i]
        @best_scores[i] = score
        @best_positions[i] = @particles[i].dup
      end
    end
    update_global_best
  end
end

class Optimization
  def initialize(swarm, objective_function)
    @swarm = swarm
    @objective_function = objective_function
  end

  def run
    loop do
      @swarm.update_particles
      @swarm.evaluate(@objective_function)
    end
  end
end

def objective_function(position)
  position.sum { |x| x ** 2 }
end

def main
  size = 30
  dimensions = 2
  swarm = Swarm.new(size, dimensions)
  optimization = Optimization.new(swarm, method(:objective_function))
  optimization.run
end

main