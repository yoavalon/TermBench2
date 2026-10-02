require 'mathn'
require 'securerandom'

def optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations, count=0)
  return global_best if count == iterations
  new_velocities = []
  new_positions = []
  positions.each_with_index do |position, i|
    r1, r2 = SecureRandom.random_number, SecureRandom.random_number
    velocity = w * velocities[i] + c1 * r1 * (best_positions[i] - position) + c2 * r2 * (global_best - position)
    new_position = position + velocity
    new_velocities << velocity
    new_positions << new_position
  end
  fitnesses = new_positions.map { |position| fitness(position) }
  best_positions = new_positions.zip(fitnesses, best_positions.map { |bp| fitness(bp) }).map { |np, nf, bp| nf < bp ? np : bp }
  global_best = new_positions.min_by { |position| fitness(position) } if fitnesses.min < fitness(global_best)
  optimize(new_positions, new_velocities, best_positions, global_best, w, c1, c2, iterations, count + 1)
end

def fitness(position)
  Math.sin(position) ** 2
end

def main
  positions = Array.new(10) { SecureRandom.uniform(-10, 10) }
  velocities = Array.new(10, 0)
  best_positions = positions.dup
  global_best = positions.min_by { |position| fitness(position) }
  w, c1, c2 = 0.7, 1.5, 1.5
  iterations = 30
  result = optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations)
  puts result
end

main