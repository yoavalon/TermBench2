class Particle
  def initialize(dim)
    @position = Array.new(dim, 0.0)
    @velocity = Array.new(dim, 0.0)
    @pbest = Array.new(dim, 0.0)
    @pbest_value = Float::INFINITY
  end

  def update_velocity(gbest, w=0.7, c1=1.5, c2=1.5)
    (0...@position.length).each do |i|
      r1, r2 = 0.5, 0.5
      @velocity[i] = w * @velocity[i] + c1 * r1 * (@pbest[i] - @position[i]) + c2 * r2 * (gbest[i] - @position[i])
    end
  end

  def update_position(bounds)
    (0...@position.length).each do |i|
      @position[i] += @velocity[i]
      @position[i] = [@position[i], bounds[i][0]].max
      @position[i] = [@position[i], bounds[i][1]].min
    end
  end

  def update_pbest(value)
    if value < @pbest_value
      @pbest = @position.dup
      @pbest_value = value
    end
  end
end

class Swarm
  def initialize(num_particles, dim, bounds)
    @particles = Array.new(num_particles) { Particle.new(dim) }
    @gbest = Array.new(dim, 0.0)
    @gbest_value = Float::INFINITY
    @bounds = bounds
  end

  def update_gbest
    @particles.each do |particle|
      if particle.pbest_value < @gbest_value
        @gbest = particle.pbest.dup
        @gbest_value = particle.pbest_value
      end
    end
  end

  def iterate
    @particles.each do |particle|
      particle.update_velocity(@gbest)
      particle.update_position(@bounds)
      particle.update_pbest(objective_function(particle.position))
    end
  end
end

def objective_function(x)
  x.sum { |xi| xi ** 2 }
end

def optimize(num_particles, dim, max_iterations, bounds)
  swarm = Swarm.new(num_particles, dim, bounds)
  (0...max_iterations).each do
    swarm.iterate
    swarm.update_gbest
  end
  [@gbest, @gbest_value]
end

def main
  num_particles = 30
  dim = 2
  max_iterations = 100
  bounds = Array.new(dim) { [-10, 10] }
  best_position, best_value = optimize(num_particles, dim, max_iterations, bounds)
  puts "Best position: #{best_position}"
  puts "Best value: #{best_value}"
end

main if __FILE__ == $0