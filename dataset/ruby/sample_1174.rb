class Particle
  attr_accessor :position, :velocity, :best_position, :best_score

  def initialize(dimensions)
    @position = Array.new(dimensions, 0.0)
    @velocity = Array.new(dimensions, 0.0)
    @best_position = Array.new(dimensions, 0.0)
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    dimensions = @position.length
    dimensions.times do |i|
      r1, r2 = 0.5, 0.5
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position(bounds)
    dimensions = @position.length
    dimensions.times do |i|
      @position[i] += @velocity[i]
      @position[i] = [bounds[i][0], [@position[i], bounds[i][1]].min].max
    end
  end

  def evaluate(score_function)
    @best_score = score_function.call(@position)
    if @best_score < score_function.call(@best_position)
      @best_position = @position.dup
    end
  end
end

class Swarm
  attr_accessor :particles, :global_best, :global_best_score, :bounds, :w, :c1, :c2

  def initialize(dimensions, num_particles, bounds, w, c1, c2)
    @particles = Array.new(num_particles) { Particle.new(dimensions) }
    @global_best = Array.new(dimensions, 0.0)
    @global_best_score = Float::INFINITY
    @bounds = bounds
    @w = w
    @c1 = c1
    @c2 = c2
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_score < @global_best_score
        @global_best_score = particle.best_score
        @global_best = particle.best_position.dup
      end
    end
  end

  def iterate(score_function)
    @particles.each do |particle|
      particle.update_velocity(@global_best, @w, @c1, @c2)
      particle.update_position(@bounds)
      particle.evaluate(score_function)
    end
    update_global_best
  end
end

def main
  dimensions = 2
  num_particles = 10
  bounds = [(-10, 10), (-10, 10)]
  w = 0.7
  c1 = 2.0
  c2 = 2.0

  score_function = proc do |position|
    position.sum { |x| x ** 2 }
  end

  swarm = Swarm.new(dimensions, num_particles, bounds, w, c1, c2)
  loop do
    swarm.iterate(score_function)
  end
end

main