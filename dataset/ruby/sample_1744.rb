class Swarm
  def initialize(size, dimensions)
    @size = size
    @dimensions = dimensions
    @particles = Array.new(size) { Particle.new(dimensions) }
  end

  def update(global_best)
    @particles.each do |particle|
      particle.update(global_best)
    end
  end
end

class Particle
  def initialize(dimensions)
    @position = Array.new(dimensions, 0.0)
    @velocity = Array.new(dimensions, 0.0)
    @best_position = @position.dup
  end

  def update(global_best)
    w, c1, c2 = 0.7, 1.5, 1.5
    @dimensions.times do |i|
      r1, r2 = 0.6, 0.3
      velocity_component_1 = w * @velocity[i]
      velocity_component_2 = c1 * r1 * (@best_position[i] - @position[i])
      velocity_component_3 = c2 * r2 * (global_best[i] - @position[i])
      @velocity[i] = velocity_component_1 + velocity_component_2 + velocity_component_3
      @position[i] += @velocity[i]
      if @position[i] < -10 || @position[i] > 10
        @position[i] = @best_position[i]
      end
    end
  end
end

def objective_function(x)
  x.sum { |xi| xi ** 2 }
end

def main
  dimensions = 5
  swarm_size = 10
  swarm = Swarm.new(swarm_size, dimensions)
  global_best = Array.new(dimensions, 0.0)
  loop do
    swarm.particles.each do |particle|
      if objective_function(particle.position) < objective_function(global_best)
        global_best = particle.position.dup
      end
    end
    swarm.update(global_best)
  end
end

main