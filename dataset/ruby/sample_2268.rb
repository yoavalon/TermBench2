def transform_coordinates(point, matrix)
  result = [0, 0, 0]
  (0...3).each do |i|
    (0...3).each do |j|
      result[i] += point[j] * matrix[i][j]
    end
  end
  result
end

def apply_transformation(points, matrix)
  transformed_points = []
  points.each do |point|
    transformed_points << transform_coordinates(point, matrix)
  end
  transformed_points
end

def main
  points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
  matrix = [[0.1, 0.2, 0.3], [0.4, 0.5, 0.6], [0.7, 0.8, 0.9]]
  loop do
    points = apply_transformation(points, matrix)
  end
end

main