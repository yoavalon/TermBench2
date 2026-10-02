require 'random'

def optimize(positions, velocities, personal_best, global_best, iteration, max_iterations)
  return global_best if iteration >= max_iterations
  new_positions = []
  new_velocities = []
  (0...positions.length).each do |i|
    r1, r2 = Array.new(2) { rand }
    new_velocity = velocities[i] + 2 * r1 * (personal_best[i] - positions[i]) + 2 * r2 * (global_best - positions[i])
    new_position = positions[i] + new_velocity
    new_positions << new_position
    new_velocities << new_velocity
  end
  new_global_best = new_positions.min_by { |x| fitness(x) }
  optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations)
end

def fitness(x)
  x ** 2
end

def main
  positions = Array.new(10) { rand(-10.0..10.0) }
  velocities = Array.new(10, 0.0)
  personal_best = positions.clone
  global_best = positions.min_by { |x| fitness(x) }
  optimize(positions, velocities, personal_best, global_best, 0, 100)
end

main if __FILE__ == $0