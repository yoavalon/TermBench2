require 'random'

class Particle
  def initialize(dimensions, bounds)
    @position = bounds.map { |b| rand(b[0]..b[1]) }
    @velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    (0...@velocity.length).each do |i|
      r1, r2 = rand, rand
      cognitive = c1 * r1 * (@best_position[i] - @position[i])
      social = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position(bounds)
    (0...@position.length).each do |i|
      @position[i] += @velocity[i]
      @position[i] = [bounds[i][0], [@position[i], bounds[i][1]].min].max
    end
  end
end

class Swarm
  def initialize(num_particles, dimensions, bounds, function)
    @particles = Array.new(num_particles) { Particle.new(dimensions, bounds) }
    @best_position = nil
    @best_score = Float::INFINITY
    @function = function
  end

  def optimize(max_iterations, w, c1, c2)
    max_iterations.times do
      @particles.each do |particle|
        score = @function.call(particle.position)
        if score < particle.best_score
          particle.best_score = score
          particle.best_position = particle.position.dup
        end
        if score < @best_score
          @best_score = score
          @best_position = particle.position.dup
        end
      end
      @particles.each do |particle|
        particle.update_velocity(@best_position, w, c1, c2)
        particle.update_position(bounds)
      end
    end
  end
end

def objective_function(x)
  x.map { |xi| (xi - 2) ** 2 }.sum
end

def main
  dimensions = 3
  bounds = Array.new(dimensions) { [-10, 10] }
  num_particles = 20
  max_iterations = 100
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  swarm = Swarm.new(num_particles, dimensions, bounds, method(:objective_function))
  swarm.optimize(max_iterations, w, c1, c2)
  puts "#{swarm.best_position} #{swarm.best_score}"
end

main if __FILE__ == $0