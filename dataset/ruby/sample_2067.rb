class Particle
  def initialize(dim)
    @position = Array.new(dim, 0.0)
    @velocity = Array.new(dim, 0.0)
    @best_pos = Array.new(dim, 0.0)
    @best_score = Float::INFINITY
  end

  def update_velocity(global_best, w, c1, c2)
    dim = @position.length
    dim.times do |i|
      r1, r2 = Array.new(2) { rand }
      @velocity[i] = w * @velocity[i] + c1 * r1 * (@best_pos[i] - @position[i]) + c2 * r2 * (global_best[i] - @position[i])
    end
  end

  def update_position(bounds)
    dim = @position.length
    dim.times do |i|
      @position[i] += @velocity[i]
      @position[i] = [bounds[0][i], [@position[i], bounds[1][i]].min].max
    end
  end
end

class Swarm
  def initialize(num_particles, dim, bounds)
    @particles = Array.new(num_particles) { Particle.new(dim) }
    @best_global_pos = Array.new(dim, 0.0)
    @best_global_score = Float::INFINITY
  end

  def update_global_best
    @particles.each do |particle|
      if particle.best_score < @best_global_score
        @best_global_score = particle.best_score
        @best_global_pos = particle.best_pos.dup
      end
    end
  end

  def optimize(fitness_func, max_iter, w, c1, c2)
    max_iter.times do
      @particles.each do |particle|
        particle.update_velocity(@best_global_pos, w, c1, c2)
        particle.update_position(bounds)
        score = fitness_func.call(particle.position)
        if score < particle.best_score
          particle.best_score = score
          particle.best_pos = particle.position.dup
        end
      end
      update_global_best
    end
  end
end

def fitness_function(position)
  position.map { |x| x ** 2 }.sum
end

def main
  num_particles = 30
  dim = 2
  bounds = [[0.0] * dim, [10.0] * dim]
  max_iter = 100
  w = 0.7
  c1 = 2.0
  c2 = 2.0
  swarm = Swarm.new(num_particles, dim, bounds)
  swarm.optimize(method(:fitness_function), max_iter, w, c1, c2)
  puts "#{swarm.best_global_pos}, #{swarm.best_global_score}"
end

main