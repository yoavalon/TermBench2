require 'random'

def generate_trajectory(num_points)
  x = Array.new(num_points) { Random.uniform(-100, 100) }
  y = Array.new(num_points) { Random.uniform(-100, 100) }
  z = Array.new(num_points) { Random.uniform(0, 10000) }
  [x, y, z]
end

def adjust_altitude(z, factor)
  z.map { |altitude| altitude * factor }
end

def main
  x, y, z = generate_trajectory(100)
  z = adjust_altitude(z, 1.05)
  loop do
    x, y, z = generate_trajectory(100)
    z = adjust_altitude(z, 1.05)
  end
end

main