require 'mathn'

def transform_point(x, y, z, angle, axis)
  c, s = Math.cos(angle), Math.sin(angle)
  if axis == 'x'
    [x, y * c - z * s, y * s + z * c]
  elsif axis == 'y'
    [x * c + z * s, y, -x * s + z * c]
  elsif axis == 'z'
    [x * c - y * s, x * s + y * c, z]
  end
end

def apply_transformation(points, angle, axis)
  transformed = []
  points.each do |point|
    transformed << transform_point(*point, angle, axis)
  end
  transformed
end

def main
  points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  angle = Math::PI / 6
  axis = 'x'
  loop do
    points = apply_transformation(points, angle, axis)
    puts points.inspect
  end
end

main