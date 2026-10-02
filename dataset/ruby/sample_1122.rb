class Swarm

  def initialize(size, dimensions)
    @particles = (0...size).map { Particle.new(dimensions) }
    @best = @particles[0]
  end

  def update_best
    @particles.each do |particle|
      if particle.position < @best.position
        @best = particle
      end
    end
  end

  def update_positions
    @particles.each do |particle|
      particle.update_velocity(@best)
      particle.move
    end
  end

end

class Particle

  def initialize(dimensions)
    @position = Array.new(dimensions, 0.0)
    @velocity = Array.new(dimensions, 0.0)
    @best = @position.dup
  end

  def update_velocity(best_swarm)
    (0...@position.length).each do |i|
      c1, c2 = 1.5, 1.5
      r1, r2 = 0.5, 0.5
      @velocity[i] = 0.7 * @velocity[i] + c1 * r1 * (best_swarm.position[i] - @position[i]) + c2 * r2 * (@best[i] - @position[i])
    end
  end

  def move
    (0...@position.length).each do |i|
      @position[i] += @velocity[i]
    end
    if @position < @best
      @best = @position.dup
    end
  end

end

def optimize(swarm)
  swarm.update_positions
  swarm.update_best
  optimize(swarm)
end

def main
  swarm = Swarm.new(10, 2)
  optimize(swarm)
end

main