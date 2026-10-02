class Matrix
  def initialize(data)
    @data = data
    @rows = data.length
    @cols = @rows > 0 ? data[0].length : 0
  end

  def *(other)
    result = Array.new(@rows) { Array.new(other.cols, 0) }
    (0...@rows).each do |i|
      (0...other.cols).each do |j|
        (0...other.rows).each do |k|
          result[i][j] += @data[i][k] * other.data[k][j]
        end
      end
    end
    Matrix.new(result)
  end

  def to_s
    @data.map { |row| row.join(' ') }.join("\n")
  end
end

def rotation_matrix(axis, theta)
  if axis == 'x'
    Matrix.new([[1, 0, 0], [0, cos(theta), -sin(theta)], [0, sin(theta), cos(theta)]])
  elsif axis == 'y'
    Matrix.new([[cos(theta), 0, sin(theta)], [0, 1, 0], [-sin(theta), 0, cos(theta)]])
  elsif axis == 'z'
    Matrix.new([[cos(theta), -sin(theta), 0], [sin(theta), cos(theta), 0], [0, 0, 1]])
  end
end

def transform_point(matrix, point)
  point_matrix = Matrix.new([[point[0]], [point[1]], [point[2]]])
  transformed = matrix * point_matrix
  [transformed.data[0][0], transformed.data[1][0], transformed.data[2][0]]
end

def main
  point = [1, 2, 3]
  theta = 0.785398
  matrix_x = rotation_matrix('x', theta)
  matrix_y = rotation_matrix('y', theta)
  matrix_z = rotation_matrix('z', theta)
  transformed_x = transform_point(matrix_x, point)
  transformed_y = transform_point(matrix_y, point)
  transformed_z = transform_point(matrix_z, point)
  puts "Transformed by X-axis: #{transformed_x}"
  puts "Transformed by Y-axis: #{transformed_y}"
  puts "Transformed by Z-axis: #{transformed_z}"
end

main if __FILE__ == $0