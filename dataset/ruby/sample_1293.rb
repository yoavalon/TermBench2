def transform_coordinates(data)
  require 'matrix'
  matrix = Matrix[[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  data.each_with_index do |point, i|
    data[i] = matrix * Matrix.columns([point]).to_a.flatten
  end
  data
end

if __FILE__ == $0
  points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  result = transform_coordinates(points)
  puts result.inspect
end