class Vector3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def subtract(other)
    Vector3D.new(@x - other.x, @y - other.y, @z - other.z)
  end

  def scale(scalar)
    Vector3D.new(@x * scalar, @y * scalar, @z * scalar)
  end

  def magnitude
    Math.sqrt(@x ** 2 + @y ** 2 + @z ** 2)
  end
end

class Transformation
  def initialize(rotation_matrix, translation_vector)
    @rotation_matrix = rotation_matrix
    @translation_vector = translation_vector
  end

  def apply(vector)
    x = vector.x * @rotation_matrix[0][0] + vector.y * @rotation_matrix[0][1] + vector.z * @rotation_matrix[0][2]
    y = vector.x * @rotation_matrix[1][0] + vector.y * @rotation_matrix[1][1] + vector.z * @rotation_matrix[1][2]
    z = vector.x * @rotation_matrix[2][0] + vector.y * @rotation_matrix[2][1] + vector.z * @rotation_matrix[2][2]
    translated_vector = Vector3D.new(x, y, z).add(@translation_vector)
    translated_vector
  end
end

def generate_sequence(start, transformation, steps)
  sequence = []
  current_vector = start
  steps.times do
    sequence << current_vector
    current_vector = transformation.apply(current_vector)
  end
  sequence
end

def main
  start_vector = Vector3D.new(1, 0, 0)
  rotation_matrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]]
  translation_vector = Vector3D.new(1, 1, 1)
  transformation = Transformation.new(rotation_matrix, translation_vector)
  sequence = generate_sequence(start_vector, transformation, 10)
  sequence.each do |vector|
    puts "({vector.x}, {vector.y}, {vector.z})"
  end
end

main if __FILE__ == $0