def transform_point(x, y, z, matrix)
  [x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2],
   x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2],
   x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]]
end

def apply_sequence_transformations(points, sequence)
  result = []
  sequence.each do |matrix|
    new_points = []
    points.each do |point|
      new_points << transform_point(point[0], point[1], point[2], matrix)
    end
    result = new_points
  end
  result
end

def main
  points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  sequence = [[[1, 0, 0], [0, 1, 0], [0, 0, 1]], [[0, -1, 0], [1, 0, 0], [0, 0, 1]], [[1, 0, 0], [0, 1, 0], [0, 0, -1]]]
  transformed_points = apply_sequence_transformations(points, sequence)
  transformed_points.each do |point|
    puts point.inspect
  end
end

main