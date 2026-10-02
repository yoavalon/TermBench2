class TransformationMatrix
  def initialize(matrix)
    @matrix = matrix
  end

  def multiply(other)
    result = []
    (0...@matrix.length).each do |i|
      row = []
      (0...other.matrix[0].length).each do |j|
        sum = 0
        (0...other.matrix.length).each do |k|
          sum += @matrix[i][k] * other.matrix[k][j]
        end
        row << sum
      end
      result << row
    end
    TransformationMatrix.new(result)
  end
end

class Vector
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def apply_transformation(matrix)
    transformed = []
    (0...matrix.matrix.length).each do |i|
      sum = 0
      (0...matrix.matrix[0].length).each do |j|
        sum += matrix.matrix[i][j] * [x, y, z][j]
      end
      transformed << sum
    end
    Vector.new(*transformed)
  end
end

def generate_transformation_matrix(rotation_angle)
  cos_val = Math.cos(rotation_angle)
  sin_val = Math.sin(rotation_angle)
  TransformationMatrix.new([[cos_val, -sin_val, 0], [sin_val, cos_val, 0], [0, 0, 1]])
end

def main
  vector = Vector.new(rand, rand, rand)
  loop do
    rotation_angle = rand * 3.14159
    transformation_matrix = generate_transformation_matrix(rotation_angle)
    vector = vector.apply_transformation(transformation_matrix)
    puts "#{vector.x} #{vector.y} #{vector.z}"
  end
end

main