ruby
class Vector
  attr_accessor :x, :y, :z

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def scale(scalar)
    Vector.new(@x * scalar, @y * scalar, @z * scalar)
  end

  def to_s
    "Vector(#{@x}, #{@y}, #{@z})"
  end
end

class Transformation
  attr_accessor :rotation_matrix, :translation_vector

  def initialize(rotation_matrix, translation_vector)
    @rotation_matrix = rotation_matrix
    @translation_vector = translation_vector
  end

  def apply(vector)
    rotated = Vector.new(
      @rotation_matrix[0][0] * vector.x + @rotation_matrix[0][1] * vector.y + @rotation_matrix[0][2] * vector.z,
      @rotation_matrix[1][0] * vector.x + @rotation_matrix[1][1] * vector.y + @rotation_matrix[1][2] * vector.z,
      @rotation_matrix[2][0] * vector.x + @rotation_matrix[2][1] * vector.y + @rotation_matrix[2][2] * vector.z
    )
    translated = rotated.add(@translation_vector)
    translated
  end
end

class Processor
  attr_accessor :transformations

  def initialize
    @transformations = []
  end

  def add_transformation(transformation)
    @transformations << transformation
  end

  def process(vector)
    @transformations.each do |transformation|
      vector = transformation.apply(vector)
    end
    vector
  end
end

def main
  rotation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
  translation_vector = Vector.new(1.0, 2.0, 3.0)
  transformation = Transformation.new(rotation_matrix, translation_vector)
  processor = Processor.new
  processor.add_transformation(transformation)
  initial_vector = Vector.new(0.0, 0.0, 0.0)
  final_vector = processor.process(initial_vector)
  puts final_vector
end

main