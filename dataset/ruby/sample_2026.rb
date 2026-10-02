require 'random'

def initialize_particles(size, dimensions)
  particles = []
  size.times do
    position = Array.new(dimensions) { rand(-10.0..10.0) }
    velocity = Array.new(dimensions) { rand(-1.0..1.0) }
    pbest_position = position.dup
    pbest_value = Float::INFINITY
    particles << { position: position, velocity: velocity, pbest_position: pbest_position, pbest_value: pbest_value }
  end
  particles
end

def update_velocity(particles, gbest_position, w=0.7, c1=1.5, c2=1.5)
  particles.each do |particle|
    dimensions = particle[:position].length
    dimensions.times do |i|
      r1 = rand
      r2 = rand
      cognitive = c1 * r1 * (particle[:pbest_position][i] - particle[:position][i])
      social = c2 * r2 * (gbest_position[i] - particle[:position][i])
      particle[:velocity][i] = w * particle[:velocity][i] + cognitive + social
    end
  end
end

def update_position(particles, bounds)
  particles.each do |particle|
    dimensions = particle[:position].length
    dimensions.times do |i|
      particle[:position][i] += particle[:velocity][i]
      particle[:position][i] = [bounds[0], [particle[:position][i], bounds[1]].min].max
    end
  end
end

def evaluate(particles, objective_function)
  particles.each do |particle|
    value = objective_function(particle[:position])
    if value < particle[:pbest_value]
      particle[:pbest_value] = value
      particle[:pbest_position] = particle[:position].dup
    end
  end
end

def find_gbest(particles)
  gbest_value = Float::INFINITY
  gbest_position = nil
  particles.each do |particle|
    if particle[:pbest_value] < gbest_value
      gbest_value = particle[:pbest_value]
      gbest_position = particle[:pbest_position].dup
    end
  end
  gbest_position
end

def optimize(objective_function, dimensions, size, iterations, bounds)
  particles = initialize_particles(size, dimensions)
  gbest_position = find_gbest(particles)
  iterations.times do
    update_velocity(particles, gbest_position)
    update_position(particles, bounds)
    evaluate(particles, objective_function)
    gbest_position = find_gbest(particles)
  end
  gbest_position
end

def main
  sphere_function = lambda do |x|
    x.map { |xi| xi ** 2 }.sum
  end
  dimensions = 30
  size = 30
  iterations = 100
  bounds = [-10, 10]
  result = optimize(sphere_function, dimensions, size, iterations, bounds)
  puts result.inspect
end

main if __FILE__ == $0