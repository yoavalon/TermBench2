require 'random'

def initialize_particles(num_particles, dimensions, bounds)
  particles = []
  num_particles.times do
    particle = dimensions.times.map { rand(bounds[0]..bounds[1]) }
    particles << particle
  end
  particles
end

def update_positions(particles, velocities, bounds)
  new_positions = []
  particles.each_with_index do |particle, i|
    new_position = particle.zip(velocities[i]).map { |p, v| [bounds[0], [bounds[1], p + v].min].max }
    new_positions << new_position
  end
  new_positions
end

def main
  num_particles = 30
  dimensions = 2
  bounds = [0, 10]
  particles = initialize_particles(num_particles, dimensions, bounds)
  velocities = num_particles.times.map { dimensions.times.map { rand(-1.0..1.0) } }
  100.times do
    particles = update_positions(particles, velocities, bounds)
  end
  puts particles
end

main