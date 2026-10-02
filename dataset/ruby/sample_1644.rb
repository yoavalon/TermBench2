require 'random'

def update_position(position, velocity, best_position, global_best)
  dimensions = position.length
  for i in 0...dimensions
    r1, r2 = rand, rand
    cognitive = r1 * (best_position[i] - position[i])
    social = r2 * (global_best[i] - position[i])
    velocity[i] = 0.7 * velocity[i] + cognitive + social
    position[i] += velocity[i]
  end
end

def optimize
  dimensions = 30
  swarm_size = 50
  positions = Array.new(swarm_size) { Array.new(dimensions) { rand } }
  velocities = Array.new(swarm_size) { Array.new(dimensions) { rand } }
  best_positions = positions.map(&:dup)
  global_best = best_positions.min_by { |x| x.sum }

  loop do
    for i in 0...swarm_size
      update_position(positions[i], velocities[i], best_positions[i], global_best)
      fitness = positions[i].sum
      if fitness < best_positions[i].sum
        best_positions[i] = positions[i].dup
        if fitness < global_best.sum
          global_best = positions[i].dup
        end
      end
    end
  end
end

def main
  optimize
end

main