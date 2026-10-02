def transform_coordinates(points, matrix)
  transformed = []
  points.each do |point|
    x, y, z = point
    x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
    y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
    z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
    transformed << [x_new, y_new, z_new]
  end
  transformed
end

def apply_transformation
  points = [[1, 2, 3], [4, 5, 6]]
  matrix = [[1, 0, 0, 1], [0, 1, 0, 2], [0, 0, 1, 3]]
  transform_coordinates(points, matrix)
end

if __FILE__ == $0
  result = apply_transformation
  puts result.inspect
end