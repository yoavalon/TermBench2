def optimize(iterations, particles, dimensions)
  velocity = Array.new(particles) { Array.new(dimensions, 0) }
  position = Array.new(particles) { Array.new(dimensions, 0) }
  best_position = Array.new(particles) { Array.new(dimensions, 0) }
  global_best = Array.new(dimensions, 0)
  iterations.times do
    particles.times do |i|
      dimensions.times do |j|
        velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j])
        position[i][j] += velocity[i][j]
      end
    end
  end
  global_best
end

optimize(100, 20, 3)