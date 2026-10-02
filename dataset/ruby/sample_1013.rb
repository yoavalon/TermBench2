require 'matrix'

def update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
  particles.each_with_index do |particle, i|
    particle.each_with_index do |_, j|
      r1, r2 = rand, rand
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
  update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
  update_position(particles, velocities)
  optimize(particles, velocities, pbest, gbest, w, c1, c2)
end

def main
  num_particles = 10
  dimensions = 2
  particles = Array.new(num_particles) { Array.new(dimensions) { rand(-10.0..10.0) } }
  velocities = Array.new(num_particles) { Array.new(dimensions) { rand(-1.0..1.0) } }
  pbest = particles.dup
  gbest = particles.min_by { |particle| fitness(particle) }
  w, c1, c2 = 0.7, 1.5, 1.5
  optimize(particles, velocities, pbest, gbest, w, c1, c2)
end

def fitness(position)
  position.map { |x| x ** 2 }.sum
end

main