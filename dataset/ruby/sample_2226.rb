require 'mathn'

def transform_point(x, y, z, angle, axis)
  if axis == 'x'
    y, z = [y * Math.cos(angle) - z * Math.sin(angle), y * Math.sin(angle) + z * Math.cos(angle)]
  elsif axis == 'y'
    x, z = [x * Math.cos(angle) + z * Math.sin(angle), -x * Math.sin(angle) + z * Math.cos(angle)]
  elsif axis == 'z'
    x, y = [x * Math.cos(angle) - y * Math.sin(angle), x * Math.sin(angle) + y * Math.cos(angle)]
  end
  [x, y, z]
end

def rotate_point(x, y, z, angle, axis)
  while true
    x, y, z = transform_point(x, y, z, angle, axis)
    puts "Transformed Point: (#{'%.10f' % x}, #{'%.10f' % y}, #{'%.10f' % z})"
  end
end

def main
  x, y, z = 1.0, 2.0, 3.0
  angle = Math::PI / 4
  axis = 'z'
  rotate_point(x, y, z, angle, axis)
end

main