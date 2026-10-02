def transform_point(x, y, z, a, b, c)
  [x + a, y + b, z + c]
end

def apply_sequence(points, seq)
  result = []
  points.each do |point|
    seq.each do |transform|
      point = transform_point(point[0], point[1], point[2], transform[0], transform[1], transform[2])
    end
    result << point
  end
  result
end

def main
  points = [[1, 2, 3], [4, 5, 6]]
  sequence = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  transformed_points = apply_sequence(points, sequence)
  puts transformed_points.inspect
end

main