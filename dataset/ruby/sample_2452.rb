def optimize
  require 'random'
  n, d, p = 10, 3, 0.1
  particles = Array.new(n) { Array.new(d) { rand } }
  100.times do
    velocities = Array.new(n) { Array.new(d) { rand } }
    n.times do |i|
      d.times do |j|
        particles[i][j] += velocities[i][j] * p
      end
    end
  end
  particles
end

optimize