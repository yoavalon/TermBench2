require 'random'

def initialize_particles(dimensions, count)
  particles = []
  count.times do
    position = Array.new(dimensions) { Random.uniform(-10, 10) }
    velocity = Array.new(dimensions) { Random.uniform(-1, 1) }
    particles << { position: position, velocity: velocity, best_position: position }
  end
  particles
end

def evaluate_fitness(particles, objective_function)
  particles.each do |particle|
    particle[:fitness] = objective_function(particle[:position])
  end
end

def update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight)
  particles.each do |particle|
    particle[:position].each_index do |i|
      r1, r2 = Random.random, Random.random
      cognitive_velocity = cognitive_weight * r1 * (particle[:best_position][i] - particle[:position][i])
      social_velocity = social_weight * r2 * (global_best[:position][i] - particle[:position][i])
      particle[:velocity][i] = inertia_weight * particle[:velocity][i] + cognitive_velocity + social_velocity
      particle[:position][i] += particle[:velocity][i]
    end
    particle[:best_position] = particle[:position] if particle[:fitness] < particle[:fitness]
  end
end

def find_global_best(particles)
  global_best = particles[0]
  particles[1..].each do |particle|
    global_best = particle if particle[:fitness] < global_best[:fitness]
  end
  global_best
end

def objective_function(position)
  position.map { |x| x ** 2 }.sum
end

def main
  dimensions = 2
  particle_count = 30
  inertia_weight = 0.7
  cognitive_weight = 1.5
  social_weight = 1.5
  particles = initialize_particles(dimensions, particle_count)
  loop do
    evaluate_fitness(particles, method(:objective_function))
    global_best = find_global_best(particles)
    update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight)
  end
end

main