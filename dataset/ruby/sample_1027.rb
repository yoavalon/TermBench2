ruby
def update_velocity(pos, vel, best_pos, global_best)
  w = 0.7
  c1 = 1.5
  c2 = 1.5
  r1, r2 = 0.5, 0.5
  new_vel = w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos)
  return new_vel
end

def update_position(pos, vel)
  return pos + vel
end

def optimize(func, bounds, n_particles=30, max_iter=1000)
  particles = (0...n_particles).map { bounds[0] + (bounds[1] - bounds[0]) * _1.to_f / n_particles }
  velocities = Array.new(n_particles, 0)
  personal_best = particles.dup
  global_best = particles.min_by { |x| func.call(x) }

  def iterate(i)
    nonlocal_particles, nonlocal_velocities, nonlocal_personal_best, nonlocal_global_best = binding.local_variable_get(:particles), binding.local_variable_get(:velocities), binding.local_variable_get(:personal_best), binding.local_variable_get(:global_best)
    (0...n_particles).each do |j|
      nonlocal_velocities[j] = update_velocity(nonlocal_particles[j], nonlocal_velocities[j], nonlocal_personal_best[j], nonlocal_global_best)
      nonlocal_particles[j] = update_position(nonlocal_particles[j], nonlocal_velocities[j])
      if func.call(nonlocal_particles[j]) < func.call(nonlocal_personal_best[j])
        nonlocal_personal_best[j] = nonlocal_particles[j]
      end
    end
    nonlocal_global_best = nonlocal_personal_best.min_by { |x| func.call(x) }
    iterate(i + 1)
  end
  iterate(0)
end

def main
  def test_func(x)
    return x ** 2
  end
  bounds = [-100, 100]
  optimize(method(:test_func), bounds)
end

main