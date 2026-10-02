require 'math'

def calculate_altitude(time, velocity, acceleration)
  velocity * time + 0.5 * acceleration * time ** 2
end

def adjust_altitude(current_altitude, target_altitude, rate_of_change)
  delta = target_altitude - current_altitude
  current_altitude + [delta, rate_of_change].min
end

def main
  t = 0.0
  v = 250.0
  a = 10.0
  ta = 10000.0
  ra = 100.0
  current_altitude = 0.0
  loop do
    t += 0.1
    current_altitude = calculate_altitude(t, v, a)
    current_altitude = adjust_altitude(current_altitude, ta, ra)
    puts "Time: #{t.round(1)}, Altitude: #{current_altitude.round(2)}"
  end
end

main