def initialize_particles(dim, num_particles)
  require 'securerandom'
  particles = Array.new(num_particles) { Array.new(dim) { SecureRandom.random_number } }
  velocities = Array.new(num_particles) { Array.new(dim) { SecureRandom.random_number } }
  best_positions = particles.map(&:dup)
  best_scores = Array.new(num_particles, Float::INFINITY)
  return [particles, velocities, best_positions, best_scores]
end

def update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds)
  require 'securerandom'
  particles.each_with_index do |particle, i|
    particle.each_with_index do |_, j|
      r_p = SecureRandom.random_number
      r_g = SecureRandom.random_number
      velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particle[j]) + phi_g * r_g * (global_best[j] - particle[j])
      particle[j] += velocities[i][j]
      particle[j] = [bounds[0], [particle[j], bounds[1]].min].max
    end
  end
  return [particles, velocities]
end

def main
  dim = 2
  num_particles = 10
  particles, velocities, best_positions, best_scores = initialize_particles(dim, num_particles)
  global_best = Array.new(dim, Float::INFINITY)
  omega = 0.7
  phi_p = 0.2
  phi_g = 0.3
  bounds = [0, 1]
  while true
    particles, velocities = update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds)
  end
end

main