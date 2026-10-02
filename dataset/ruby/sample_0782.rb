def rotate_point(x, y, z, angle)
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  return [x_new, y_new, z]
end

def transform_coordinates(points, angle, depth)
  if depth == 0
    return points
  end
  transformed = points.map { |x, y, z| rotate_point(x, y, z, angle) }
  return transform_coordinates(transformed, angle, depth - 1)
end

def main
  initial_points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  angle = 0.7853981633974483
  depth = 5
  result = transform_coordinates(initial_points, angle, depth)
  puts result
end

main