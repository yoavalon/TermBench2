require 'random'

class Swarm
  def initialize(size)
    @particles = Array.new(size) { Particle.new(rand(-1.0..1.0), rand(-1.0..1.0)) }
    @best = @particles.min_by { |p| p.evaluate }
  end

  def update
    @particles.each do |particle|
      particle.update_velocity(@best)
      particle.move
    end
    @best = @particles.min_by { |p| p.evaluate }
  end
end

class Particle
  def initialize(x, y)
    @position = [x, y]
    @velocity = [rand(-0.1..0.1), rand(-0.1..0.1)]
    @best = @position.dup
  end

  def evaluate
    -(@position[0] ** 2 + @position[1] ** 2)
  end

  def update_velocity(global_best)
    inertia = 0.7
    cognitive = 1.5
    social = 1.5
    @velocity.each_with_index do |_, i|
      r1, r2 = rand, rand
      cognitive_component = cognitive * r1 * (@best[i] - @position[i])
      social_component = social * r2 * (global_best.position[i] - @position[i])
      @velocity[i] = inertia * @velocity[i] + cognitive_component + social_component
    end
  end

  def move
    @position.each_with_index do |_, i|
      @position[i] += @velocity[i]
      @position[i] = [@position[i], -1.0].max
      @position[i] = [@position[i], 1.0].min
    end
    if evaluate < @best[0]
      @best = @position.dup
    end
  end
end

def run
  swarm_size = 30
  swarm = Swarm.new(swarm_size)
  loop do
    swarm.update
  end
end

run