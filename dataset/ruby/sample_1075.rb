require 'random'

def update_velocity(p, g, l, w, c1, c2)
  r1, r2 = rand, rand
  w * l + c1 * r1 * (p - l) + c2 * r2 * (g - l)
end

def update_position(l, v)
  l + v
end

def swarm_search(f, bounds, n_particles, w, c1, c2)
  particles = Array.new(n_particles) { bounds.map { |b| rand(b[0]...b[1]) } }
  velocities = Array.new(n_particles) { Array.new(bounds.size, 0) }
  pbest = particles.dup
  gbest = particles.min_by { |x| f(x) }
  loop do
    n_particles.times do |i|
      velocities[i] = bounds.map.with_index do |b, j|
        update_velocity(pbest[i][j], gbest[j], particles[i][j], w, c1, c2)
      end
      particles[i] = bounds.map.with_index do |b, j|
        update_position(particles[i][j], velocities[i][j])
      end
    end
    n_particles.times do |i|
      pbest[i] = particles[i] if f(particles[i]) < f(pbest[i])
    end
    gbest = particles.min_by { |x| f(x) }
  end
end

def main
  objective = proc { |x| x.map { |xi| xi ** 2 }.sum }
  bounds = [(-10..10), (-10..10)]
  swarm_search(objective, bounds, 30, 0.7, 1.5, 1.5)
end

main