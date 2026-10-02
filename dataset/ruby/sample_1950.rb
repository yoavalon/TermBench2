ruby
require 'math'

def calculate_altitude(distance, speed, time)
  distance / (speed * time)
end

def adjust_precision(altitude, precision)
  factor = 10 ** precision
  (altitude * factor).round / factor.to_f
end

def main
  dist = 1200.5
  spd = 300.25
  t = 2.0
  precision = 2
  alt = calculate_altitude(dist, spd, t)
  adjusted_alt = adjust_precision(alt, precision)
  puts "Cruise Altitude: #{adjusted_alt}"
end

main