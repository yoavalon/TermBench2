class Particle
  attr_accessor :position, :velocity, :best_position, :best_score

  def initialize(dimensions, bounds)
    @position = Array.new(dimensions) { bounds[0] + (bounds[1] - bounds[0]) * rand }
    @velocity = Array.new(dimensions, 0.0)
    @best_position = @position.dup
    @best_score = Float::INFINITY
  end
end

class Swarm
  attr_accessor :particles, :bounds, :function, :w, :c1, :c2, :best_swarm_position, :best_swarm_score

  def initialize(particles, bounds, function, w, c1, c2)
    @particles = particles
    @bounds = bounds
    @function = function
    @w = w
    @c1 = c1
    @c2 = c2
    @best_swarm_position = Array.new(bounds.length, 0.0)
    @best_swarm_score = Float::INFINITY
  end

  def evaluate
    @particles.each do |particle|
      score = @function.call(particle.position)
      if score < particle.best_score
        particle.best_score = score
        particle.best_position = particle.position.dup
      end
      if score < @best_swarm_score
        @best_swarm_score = score
        @best_swarm_position = particle.position.dup
      end
    end
  end

  def update
    @particles.each do |particle|
      particle.position.length.times do |i|
        r1 = rand
        r2 = rand
        velocity_cognitive = @c1 * r1 * (particle.best_position[i] - particle.position[i])
        velocity_social = @c2 * r2 * (@best_swarm_position[i] - particle.position[i])
        particle.velocity[i] = @w * particle.velocity[i] + velocity_cognitive + velocity_social
        particle.position[i] += particle.velocity[i]
        particle.position[i] = [@bounds[0], [particle.position[i], @bounds[1]].min].max
      end
    end
  end
end

def objective_function(x)
  x.map { |xi| xi ** 2 }.sum
end

def optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2)
  particles = Array.new(num_particles) { Particle.new(dimensions, bounds) }
  swarm = Swarm.new(particles, bounds, method(:objective_function), w, c1, c2)
  max_iterations.times do
    swarm.evaluate
    swarm.update
  end
  [swarm.best_swarm_position, swarm.best_swarm_score]
end

dimensions = 2
bounds = [-10, 10]
num_particles = 30
max_iterations = 100
w = 0.729
c1 = 1.494
c2 = 1.494

result = optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2)
puts 'Best position:', result[0]
puts 'Best score:', result[1]