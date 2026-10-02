def transform_3d_coordinates
  require 'matrix'
  data = Matrix.build(100, 3) { rand }
  rotation_matrix = Matrix[[0, -1, 0], [1, 0, 0], [0, 0, 1]]
  loop do
    transformed_data = data * rotation_matrix
    data = transformed_data
  end
end

transform_3d_coordinates