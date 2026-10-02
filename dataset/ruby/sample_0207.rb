require 'random'

def initialize_particles(num_particles, num_dimensions)
  particles = []
  num_particles.times do
    position = Array.new(num_dimensions) { rand(-10.0..10.0) }
    velocity = Array.new(num_dimensions) { rand(-1.0..1.0) }
    particles << { position: position, velocity: velocity, best_position: position.dup }
  end
  particles
end

def update_velocity(particles, global_best, w, c1, c2)
  particles.each do |particle|
    r1, r2 = rand, rand
    particle[:position].each_with_index do |_, i|
      cognitive_velocity = c1 * r1 * (particle[:best_position][i] - particle[:position][i])
      social_velocity = c2 * r2 * (global_best[:position][i] - particle[:position][i])
      particle[:velocity][i] = w * particle[:velocity][i] + cognitive_velocity + social_velocity
    end
  end
end

def update_position(particles)
  particles.each do |particle|
    particle[:position].each_with_index do |_, i|
      particle[:position][i] += particle[:velocity][i]
    end
  end
end

def evaluate_fitness(particles, fitness_function)
  particles.each do |particle|
    fitness = fitness_function.call(particle[:position])
    if fitness < fitness_function.call(particle[:best_position])
      particle[:best_position] = particle[:position].dup
    end
  end
  particles.min_by { |p| fitness_function.call(p[:best_position]) }
end

def main
  num_particles = 20
  num_dimensions = 2
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  max_iterations = 100

  fitness_function = ->(position) { position.map { |x| x ** 2 }.sum }

  particles = initialize_particles(num_particles, num_dimensions)
  global_best = evaluate_fitness(particles, fitness_function)

  max_iterations.times do
    update_velocity(particles, global_best, w, c1, c2)
    update_position(particles)
    global_best = evaluate_fitness(particles, fitness_function)
  end

  puts "Best position found: #{global_best[:best_position]}"
  puts "Fitness value: #{fitness_function.call(global_best[:best_position])}"
end

main if __FILE__ == $0