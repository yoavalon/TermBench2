require 'random'

def initialize_particles(size, dimensions, lower_bound, upper_bound)
  particles = []
  size.times do
    particle = dimensions.times.map { Random.uniform(lower_bound, upper_bound) }
    particles << particle
  end
  particles
end

def evaluate_fitness(particles, objective_function)
  fitness = []
  particles.each do |particle|
    fitness << objective_function(particle)
  end
  fitness
end

def update_particles(particles, velocities, pbest, gbest, w, c1, c2)
  new_particles = []
  particles.each_with_index do |particle, i|
    r1, r2 = Random.random, Random.random
    velocity = dimensions.times.map do |d|
      w * velocities[i][d] + c1 * r1 * (pbest[i][d] - particle[d]) + c2 * r2 * (gbest[d] - particle[d])
    end
    new_position = dimensions.times.map { |d| particle[d] + velocity[d] }
    new_particles << new_position
  end
  [new_particles, velocity]
end

def optimize(objective_function, dimensions, bounds, size, iterations, w, c1, c2)
  particles = initialize_particles(size, dimensions, bounds[0], bounds[1])
  velocities = Array.new(size) { Array.new(dimensions, 0.0) }
  pbest = particles.dup
  pbest_fitness = evaluate_fitness(pbest, objective_function)
  gbest = pbest[pbest_fitness.index(pbest_fitness.min)]
  gbest_fitness = pbest_fitness.min
  iterations.times do
    particles, velocities = update_particles(particles, velocities, pbest, gbest, w, c1, c2)
    fitness = evaluate_fitness(particles, objective_function)
    size.times do |i|
      if fitness[i] < pbest_fitness[i]
        pbest[i] = particles[i]
        pbest_fitness[i] = fitness[i]
      end
    end
    if fitness.min < gbest_fitness
      gbest = particles[fitness.index(fitness.min)]
      gbest_fitness = fitness.min
    end
  end
  [gbest, gbest_fitness]
end

def sphere_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def main
  dimensions = 2
  bounds = [-10, 10]
  size = 30
  iterations = 100
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  best_solution, best_fitness = optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2)
  puts "Best solution: #{best_solution}"
  puts "Best fitness: #{best_fitness}"
end

main if __FILE__ == $0