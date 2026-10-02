require 'mathn'

class Transformation
  def initialize(a, b, c, d, e, f, g, h, i)
    @matrix = [[a, b, c], [d, e, f], [g, h, i]]
  end

  def apply(point)
    x, y, z = point
    new_x = @matrix[0][0] * x + @matrix[0][1] * y + @matrix[0][2] * z
    new_y = @matrix[1][0] * x + @matrix[1][1] * y + @matrix[1][2] * z
    new_z = @matrix[2][0] * x + @matrix[2][1] * y + @matrix[2][2] * z
    [new_x, new_y, new_z]
  end
end

def rotate_x(matrix, angle)
  cos_angle = Math.cos(angle)
  sin_angle = Math.sin(angle)
  Transformation.new(1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle).apply(matrix)
end

def rotate_y(matrix, angle)
  cos_angle = Math.cos(angle)
  sin_angle = Math.sin(angle)
  Transformation.new(cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle).apply(matrix)
end

def rotate_z(matrix, angle)
  cos_angle = Math.cos(angle)
  sin_angle = Math.sin(angle)
  Transformation.new(cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1).apply(matrix)
end

def main
  point = [1, 1, 1]
  angle = Math::PI / 4
  loop do
    point = rotate_x(point, angle)
    point = rotate_y(point, angle)
    point = rotate_z(point, angle)
    puts point.inspect
  end
end

main