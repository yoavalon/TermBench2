require 'random'

def initialize_particles(num_particles, dimensions)
  particles = []
  num_particles.times do
    position = dimensions.times.map { rand(-10.0..10.0) }
    velocity = dimensions.times.map { rand(-1.0..1.0) }
    particles << { position: position, velocity: velocity, best_position: position }
  end
  particles
end

def evaluate_fitness(particles, fitness_function)
  particles.each do |particle|
    particle[:fitness] = fitness_function(particle[:position])
  end
end

def update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight)
  particles.each do |particle|
    particle[:position].each_index do |i|
      r1, r2 = rand, rand
      cognitive_velocity = cognitive_weight * r1 * (particle[:best_position][i] - particle[:position][i])
      social_velocity = social_weight * r2 * (global_best_position[i] - particle[:position][i])
      particle[:velocity][i] = inertia_weight * particle[:velocity][i] + cognitive_velocity + social_velocity
      particle[:position][i] += particle[:velocity][i]
    end
    if fitness_function(particle[:position]) < fitness_function(particle[:best_position])
      particle[:best_position] = particle[:position]
    end
  end
end

def find_global_best(particles)
  best_particle = particles.min_by { |p| p[:fitness] }
  best_particle[:position]
end

def fitness_function(position)
  position.map { |x| x ** 2 }.sum
end

def main
  num_particles = 30
  dimensions = 2
  inertia_weight = 0.7
  cognitive_weight = 1.5
  social_weight = 1.5
  particles = initialize_particles(num_particles, dimensions)
  loop do
    evaluate_fitness(particles, fitness_function)
    global_best_position = find_global_best(particles)
    update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight)
  end
end

main