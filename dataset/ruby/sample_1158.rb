class Particle
  def initialize(position, velocity, best_position)
    @position = position
    @velocity = velocity
    @best_position = best_position
  end

  def update_velocity(global_best, w, c1, c2)
    r1, r2 = 0.5, 0.3
    new_velocity = w * @velocity + c1 * r1 * (@best_position - @position) + c2 * r2 * (global_best - @position)
    @velocity = new_velocity
  end

  def update_position
    @position += @velocity
    if @position < @best_position
      @best_position = @position
    end
  end
end

def update_global_best(particles)
  best = particles[0].best_position
  particles.each do |particle|
    if particle.best_position < best
      best = particle.best_position
    end
  end
  best
end

def optimize(particles, global_best, w, c1, c2, iterations)
  return global_best if iterations == 0
  particles.each do |particle|
    particle.update_velocity(global_best, w, c1, c2)
    particle.update_position
  end
  new_global_best = update_global_best(particles)
  optimize(particles, new_global_best, w, c1, c2, iterations - 1)
end

def main
  num_particles = 10
  initial_positions = Array.new(num_particles, 0.0)
  initial_velocities = Array.new(num_particles, 0.1)
  best_positions = Array.new(num_particles, 0.0)
  particles = initial_positions.zip(initial_velocities, best_positions).map { |pos, vel, best| Particle.new(pos, vel, best) }
  global_best = update_global_best(particles)
  w, c1, c2 = 0.7, 1.5, 1.5
  iterations = Float::INFINITY
  optimize(particles, global_best, w, c1, c2, iterations)
end

main