require 'matrix'

def initialize_particles(num_particles, dimensions)
  Array.new(num_particles) { Array.new(dimensions) { rand(-1.0..1.0) } }
end

def evaluate_fitness(position, target)
  position.zip(target).map { |p, t| (p - t) ** 2 }.sum
end

def update_velocity(velocity, position, p_best, g_best, w, c1, c2)
  r1, r2 = rand, rand
  velocity.zip(position, p_best, g_best).map { |v, x, p, g| w * v + c1 * r1 * (p - x) + c2 * r2 * (g - x) }
end

def update_position(position, velocity)
  position.zip(velocity).map { |x, v| x + v }
end

def particle_swarm(num_particles, dimensions, target, max_iterations)
  particles = initialize_particles(num_particles, dimensions)
  velocities = Array.new(num_particles) { Array.new(dimensions, 0.0) }
  p_best = particles.dup
  g_best = particles.min_by { |x| evaluate_fitness(x, target) }
  max_iterations.times do
    num_particles.times do |i|
      if evaluate_fitness(particles[i], target) < evaluate_fitness(p_best[i], target)
        p_best[i] = particles[i]
      end
    end
    g_best = p_best.min_by { |x| evaluate_fitness(x, target) }
    num_particles.times do |i|
      velocities[i] = update_velocity(velocities[i], particles[i], p_best[i], g_best, 0.7, 1.5, 1.5)
      particles[i] = update_position(particles[i], velocities[i])
    end
  end
  g_best
end

def main
  target = [0, 0]
  result = particle_swarm(30, 2, target, 100)
  puts result
end

main