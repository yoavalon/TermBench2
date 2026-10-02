require 'random'

def fitness_function(x)
  x ** 2
end

def update_position(position, velocity, w, c1, c2, pbest, gbest)
  r1, r2 = rand, rand
  velocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position)
  position = position + velocity
  [position, velocity]
end

def optimize(iterations, w, c1, c2, bounds)
  particles = Array.new(30) { rand(bounds[0]..bounds[1]) }
  velocities = Array.new(30, 0)
  pbests = particles.dup
  gbest = particles.min_by { |x| fitness_function(x) }
  iterations.times do
    particles.size.times do |i|
      particles[i], velocities[i] = update_position(particles[i], velocities[i], w, c1, c2, pbests[i], gbest)
      pbests[i] = particles[i] if fitness_function(particles[i]) < fitness_function(pbests[i])
    end
    gbest = particles.min_by { |x| fitness_function(x) }
  end
  gbest
end

def main
  iterations = 100
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  bounds = [-10, 10]
  result = optimize(iterations, w, c1, c2, bounds)
  puts result
end

main