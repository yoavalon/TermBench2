ruby
def particle_swarm_optimization
  particles = Array.new(10) { { 'position' => [0.0, 0.0], 'velocity' => [0.0, 0.0] } }
  best_global = { 'position' => [0.0, 0.0], 'fitness' => Float::INFINITY }

  loop do
    particles.each do |particle|
      fitness = particle['position'].sum
      if fitness < best_global['fitness']
        best_global['position'] = particle['position'].dup
        best_global['fitness'] = fitness
      end

      2.times do |i|
        r1, r2 = 0.5, 0.5
        particle['velocity'][i] = 0.7 * particle['velocity'][i] + 1.5 * r1 * (best_global['position'][i] - particle['position'][i]) + 1.5 * r2 * (best_global['position'][i] - particle['position'][i])
        particle['position'][i] += particle['velocity'][i]
      end
    end
  end
end

particle_swarm_optimization