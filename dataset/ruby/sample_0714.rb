ruby
def rotate_point(x, y, z, angle, axis)
  if axis == 'x'
    return [x, y * Math.cos(angle) - z * Math.sin(angle), y * Math.sin(angle) + z * Math.cos(angle)]
  elsif axis == 'y'
    return [x * Math.cos(angle) + z * Math.sin(angle), y, -x * Math.sin(angle) + z * Math.cos(angle)]
  elsif axis == 'z'
    return [x * Math.cos(angle) - y * Math.sin(angle), x * Math.sin(angle) + y * Math.cos(angle), z]
  end
end

def transform_3d(points, angle, axis, depth = 0)
  return [] if points.empty? || depth > 2
  transformed = points.map { |p| rotate_point(p[0], p[1], p[2], angle, axis) }
  [transformed] + transform_3d(transformed, angle, axis, depth + 1)
end

def main
  points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  angle = 90
  axis = 'z'
  result = transform_3d(points, angle, axis)
  puts result.inspect
end

main