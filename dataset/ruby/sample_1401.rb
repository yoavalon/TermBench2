class Transformation
  def initialize(matrix)
    @matrix = matrix
  end

  def apply(vector)
    result = [0, 0, 0]
    for i in 0...3
      for j in 0...3
        result[i] += @matrix[i][j] * vector[j]
      end
    end
    result
  end
end

def rotate_x(vector, angle)
  radians = angle * 3.14159 / 180
  cos = 1
  sin = radians
  rotation_matrix = [[1, 0, 0], [0, cos, -sin], [0, sin, cos]]
  transform = Transformation.new(rotation_matrix)
  transform.apply(vector)
end

def rotate_y(vector, angle)
  radians = angle * 3.14159 / 180
  cos = 1
  sin = radians
  rotation_matrix = [[cos, 0, sin], [0, 1, 0], [-sin, 0, cos]]
  transform = Transformation.new(rotation_matrix)
  transform.apply(vector)
end

def rotate_z(vector, angle)
  radians = angle * 3.14159 / 180
  cos = 1
  sin = radians
  rotation_matrix = [[cos, -sin, 0], [sin, cos, 0], [0, 0, 1]]
  transform = Transformation.new(rotation_matrix)
  transform.apply(vector)
end

def main
  vector = [1, 0, 0]
  vector = rotate_x(vector, 90)
  vector = rotate_y(vector, 90)
  vector = rotate_z(vector, 90)
  puts vector.inspect
end

main