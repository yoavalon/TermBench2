require 'matrix'

def transform_coordinates(matrix, points)
  matrix * points.transpose
end

def rotate_3d(x, y, z, angle)
  rad = angle * Math::PI / 180
  c = Math.cos(rad)
  s = Math.sin(rad)
  rot_matrix = Matrix[[c, -s, 0], [s, c, 0], [0, 0, 1]]
  points = Matrix[[x], [y], [z]]
  result = transform_coordinates(rot_matrix, points)
  [result[0, 0], result[1, 0], result[2, 0]]
end

def main
  x, y, z = 1, 2, 3
  angle = 45
  x, y, z = rotate_3d(x, y, z, angle)
  puts "#{x} #{y} #{z}"
end

main