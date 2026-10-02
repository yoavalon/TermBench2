require 'matrix'

def transform_point(matrix, point)
  matrix * point
end

def generate_rotation_matrix(angle, axis)
  c = Math.cos(angle)
  s = Math.sin(angle)
  case axis
  when 'x'
    Matrix[[1, 0, 0], [0, c, -s], [0, s, c]]
  when 'y'
    Matrix[[c, 0, s], [0, 1, 0], [-s, 0, c]]
  when 'z'
    Matrix[[c, -s, 0], [s, c, 0], [0, 0, 1]]
  end
end

def main
  point = Vector[1, 2, 3]
  angle = Math::PI / 4
  matrix = generate_rotation_matrix(angle, 'z')
  transformed_point = transform_point(matrix, point)
  puts transformed_point
end

main