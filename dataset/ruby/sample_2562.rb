require 'matrix'

def transform_coordinates(coords, matrix)
  coords.dot(matrix)
end

def generate_transformation_matrix(angle_x, angle_y, angle_z)
  Rx = Matrix[
    [1, 0, 0],
    [0, Math.cos(angle_x), -Math.sin(angle_x)],
    [0, Math.sin(angle_x), Math.cos(angle_x)]
  ]
  Ry = Matrix[
    [Math.cos(angle_y), 0, Math.sin(angle_y)],
    [0, 1, 0],
    [-Math.sin(angle_y), 0, Math.cos(angle_y)]
  ]
  Rz = Matrix[
    [Math.cos(angle_z), -Math.sin(angle_z), 0],
    [Math.sin(angle_z), Math.cos(angle_z), 0],
    [0, 0, 1]
  ]
  Rx * Ry * Rz
end

def main
  coords = Vector[1, 2, 3]
  angles = [Math::PI / 4, Math::PI / 3, Math::PI / 6]
  matrix = generate_transformation_matrix(*angles)
  new_coords = transform_coordinates(coords, matrix)
  puts new_coords.to_a.inspect
end

main