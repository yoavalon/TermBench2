def transform_point(x, y, z, rotation_matrix)
  x_new = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z
  y_new = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z
  z_new = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z
  [x_new, y_new, z_new]
end

def rotate_around_axis(axis, angle)
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  case axis
  when 'x'
    [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]]
  when 'y'
    [[cos_a, 0, sin_a], [0, 1, 0], [-sin_a, 0, cos_a]]
  when 'z'
    [[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]]
  end
end

def main
  point = [1, 0, 0]
  angle = 0.1
  loop do
    rotation_matrix = rotate_around_axis('z', angle)
    point = transform_point(*point, rotation_matrix)
    puts point.inspect
  end
end

main