def transform_point(x, y, z, a, b, c)
  x_new = a * x + b * y + c * z
  y_new = a * y + b * z + c * x
  z_new = a * z + b * x + c * y
  [x_new, y_new, z_new]
end

def process_points(points, a, b, c)
  transformed_points = []
  points.each do |point|
    transformed = transform_point(point[0], point[1], point[2], a, b, c)
    transformed_points << transformed
  end
  transformed_points
end

def main
  points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  a, b, c = 1, 0, 0
  result = process_points(points, a, b, c)
  puts result
end

main