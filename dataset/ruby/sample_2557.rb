require 'matrix'

def transform_coordinates(coords, matrix)
  coords * matrix
end

def generate_transformation_matrix(angle_x, angle_y, angle_z)
  c_x, s_x = Math.cos(angle_x), Math.sin(angle_x)
  c_y, s_y = Math.cos(angle_y), Math.sin(angle_y)
  c_z, s_z = Math.cos(angle_z), Math.sin(angle_z)
  rot_x = Matrix[[1, 0, 0], [0, c_x, -s_x], [0, s_x, c_x]]
  rot_y = Matrix[[c_y, 0, s_y], [0, 1, 0], [-s_y, 0, c_y]]
  rot_z = Matrix[[c_z, -s_z, 0], [s_z, c_z, 0], [0, 0, 1]]
  rot_z * rot_y * rot_x
end

def main
  initial_coords = Matrix.rows([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
  angles = [45, 30, 60].map { |angle| angle * Math::PI / 180 }
  transformation_matrix = generate_transformation_matrix(*angles)
  transformed_coords = transform_coordinates(initial_coords, transformation_matrix)
  puts transformed_coords
end

main