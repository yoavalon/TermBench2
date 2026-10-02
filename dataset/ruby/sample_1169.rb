class Swarm
  def initialize(size, dimensions)
    @particles = Array.new(size) { Particle.new(dimensions) }
    @gbest = @particles[0]
  end

  def update_gbest
    @particles.each do |particle|
      if particle.fitness < @gbest.fitness
        @gbest = particle
      end
    end
  end

  def optimize
    loop do
      @particles.each do |particle|
        particle.update_velocity(@gbest)
        particle.update_position
      end
      update_gbest
    end
  end
end

class Particle
  def initialize(dimensions)
    @position = Array.new(dimensions) { 0.0 }
    @velocity = Array.new(dimensions) { 0.0 }
    @best_position = @position.dup
    @fitness = Float::INFINITY
  end

  def update_velocity(gbest)
    @position.length.times do |i|
      r1, r2 = 0.5, 0.5
      inertia = 0.7
      @velocity[i] = inertia * @velocity[i] + r1 * (@best_position[i] - @position[i]) + r2 * (gbest.position[i] - @position[i])
    end
  end

  def update_position
    @position.length.times do |i|
      @position[i] += @velocity[i]
      if @fitness > calculate_fitness
        @best_position = @position.dup
        @fitness = calculate_fitness
      end
    end
  end

  def calculate_fitness
    @position.sum { |x| x ** 2 }
  end
end

def main
  swarm = Swarm.new(10, 2)
  swarm.optimize
end

main