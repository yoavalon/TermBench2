require 'securerandom'

def initialize_particles(dim, num_particles)
  particles = Array.new(num_particles) { Array.new(dim) { SecureRandom.random_number(-10..10) } }
  velocities = Array.new(num_particles) { Array.new(dim) { SecureRandom.random_number(-1..1) } }
  pbest_positions = particles.map(&:dup)
  pbest_values = Array.new(num_particles, Float::INFINITY)
  gbest_position = nil
  gbest_value = Float::INFINITY
  [particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value]
end

def update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func)
  particles.each_with_index do |particle, i|
    current_value = fitness_func(particle)
    if current_value < pbest_values[i]
      pbest_values[i] = current_value
      pbest_positions[i] = particle.dup
    end
    if current_value < gbest_value
      gbest_value = current_value
      gbest_position = particle.dup
    end
  end
  [gbest_value, gbest_position, pbest_values, pbest_positions]
end

def update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2)
  particles.each_with_index do |particle, i|
    particle.each_with_index do |_, j|
      r1, r2 = SecureRandom.random_number, SecureRandom.random_number
      velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particle[j]) + c2 * r2 * (gbest_position[j] - particle[j])
      particle[j] += velocities[i][j]
    end
  end
end

def fitness_func(position)
  position.map { |x| x ** 2 }.sum
end

def main
  dim = 2
  num_particles = 10
  w = 0.729
  c1 = 1.494
  c2 = 1.494
  particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value = initialize_particles(dim, num_particles)
  loop do
    gbest_value, gbest_position, pbest_values, pbest_positions = update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func)
    update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2)
  end
end

main