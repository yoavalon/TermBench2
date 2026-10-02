def update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
  particles.each_with_index do |particle, i|
    particle.each_with_index do |_, j|
      r1, r2 = 0.5, 0.5
      velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particle[j]) + c2 * r2 * (gbest[j] - particle[j])
    end
  end
end

def update_position(particles, velocities)
  particles.each_with_index do |particle, i|
    particle.each_with_index do |_, j|
      particle[j] += velocities[i][j]
    end
  end
end

def optimize(particles, velocities, pbest, gbest, w, c1, c2)
  loop do
    update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
    update_position(particles, velocities)
    particles.each_with_index do |particle, i|
      if pbest[i][0] > particle[0]
        pbest[i] = particle.dup
      end
    end
    if gbest[0] > particles.min_by { |x| x[0] }[0]
      gbest = particles.min_by { |x| x[0] }
    end
  end
end

def main
  particles = [[1, 2], [3, 4], [5, 6]]
  velocities = [[0, 0], [0, 0], [0, 0]]
  pbest = [[1, 2], [3, 4], [5, 6]]
  gbest = particles.min_by { |x| x[0] }
  w = 0.5
  c1 = 1.5
  c2 = 1.5
  optimize(particles, velocities, pbest, gbest, w, c1, c2)
end

main