require 'random'

def update_velocity(p, g, v, w, c1, c2)
  r1, r2 = [rand, rand]
  w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p)
end

def update_position(p, v)
  p + v
end

def optimize(particles, velocities, best_positions, global_best, w, c1, c2)
  new_particles = []
  new_velocities = []
  new_best_positions = []
  particles.each_with_index do |p, i|
    v = update_velocity(p, global_best, velocities[i], w, c1, c2)
    p = update_position(p, v)
    new_particles << p
    new_velocities << v
    if p < best_positions[i]
      new_best_positions << p
    else
      new_best_positions << best_positions[i]
    end
  end
  [new_particles, new_velocities, new_best_positions]
end

def swarm
  particles = Array.new(10) { rand }
  velocities = Array.new(10) { rand }
  best_positions = particles.dup
  global_best = particles.min
  w, c1, c2 = 0.7, 1.5, 1.5
  loop do
    particles, velocities, best_positions = optimize(particles, velocities, best_positions, global_best, w, c1, c2)
    global_best = best_positions.min
  end
end

swarm