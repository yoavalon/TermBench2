require 'random'

def update_position(position, velocity, p_best, g_best)
  r1, r2 = rand, rand
  c1, c2 = 1.5, 1.5
  new_velocity = velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position)
  new_position = position + new_velocity
  [new_position, new_velocity]
end

def optimize
  particles = [{position: rand(-10.0..10.0), velocity: rand(-1.0..1.0), p_best: nil}]
  g_best = particles[0][:position]
  loop do
    particles.each do |particle|
      particle[:p_best] ||= particle[:position]
      particle[:p_best] = particle[:position] if particle[:position] < particle[:p_best]
      g_best = particle[:position] if particle[:position] < g_best
    end
    particles.each do |particle|
      particle[:position], particle[:velocity] = update_position(particle[:position], particle[:velocity], particle[:p_best], g_best)
    end
  end
end

optimize