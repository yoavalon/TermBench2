class Swarm
  attr_accessor :particles, :best_position

  def initialize(size, dimensions)
    @particles = Array.new(size) { Particle.new(dimensions) }
    @best_position = nil
  end

  def update_best_position
    if @best_position.nil?
      @best_position = @particles[0].position
    else
      @particles.each do |particle|
        if particle.fitness > @best_position.fitness
          @best_position = particle.position
        end
      end
    end
  end

  def update_particles(iterations)
    if iterations > 0
      @particles.each do |particle|
        particle.update_velocity(@best_position)
        particle.update_position
      end
      update_best_position
      update_particles(iterations - 1)
    end
  end
end

class Particle
  attr_accessor :position, :velocity, :fitness

  def initialize(dimensions)
    @position = Array.new(dimensions) { 0.0 }
    @velocity = Array.new(dimensions) { 0.0 }
    @fitness = 0.0
  end

  def update_velocity(best_position)
    w, c1, c2 = 0.7, 1.5, 1.5
    @position.length.times do |i|
      r1, r2 = 0.5, 0.5
      cognitive = c1 * r1 * (best_position[i] - @position[i])
      social = c2 * r2 * (self.best_position[i] - @position[i])
      @velocity[i] = w * @velocity[i] + cognitive + social
    end
  end

  def update_position
    @position.length.times do |i|
      @position[i] += @velocity[i]
      @fitness = calculate_fitness
    end
  end

  def calculate_fitness
    @position.sum { |x| x ** 2 }
  end
end

def optimize(swarm, iterations)
  swarm.update_particles(iterations)
end

def main
  dimensions = 2
  swarm_size = 10
  iterations = 50
  swarm = Swarm.new(swarm_size, dimensions)
  optimize(swarm, iterations)
end

main if __FILE__ == $0