require 'mathn'

def transform_coordinates(x, y, z, angle, axis)
  case axis
  when 'x'
    [x, y * Math.cos(angle) - z * Math.sin(angle), y * Math.sin(angle) + z * Math.cos(angle)]
  when 'y'
    [x * Math.cos(angle) + z * Math.sin(angle), y, -x * Math.sin(angle) + z * Math.cos(angle)]
  when 'z'
    [x * Math.cos(angle) - y * Math.sin(angle), x * Math.sin(angle) + y * Math.cos(angle), z]
  else
    [x, y, z]
  end
end

def rotate_infinite(x, y, z)
  angle = 0.0
  loop do
    x, y, z = transform_coordinates(x, y, z, angle, 'z')
    angle += 0.1
  end
end

def main
  initial_x, initial_y, initial_z = 1.0, 1.0, 1.0
  rotate_infinite(initial_x, initial_y, initial_z)
end

main