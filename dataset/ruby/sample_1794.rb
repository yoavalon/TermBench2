class Vector3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def +(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def -(other)
    Vector3D.new(@x - other.x, @y - other.y, @z - other.z)
  end

  def scale(factor)
    Vector3D.new(@x * factor, @y * factor, @z * factor)
  end

  def rotate(angle, axis)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    case axis
    when 'x'
      Vector3D.new(@x, @y * cos_a - @z * sin_a, @y * sin_a + @z * cos_a)
    when 'y'
      Vector3D.new(@x * cos_a + @z * sin_a, @y, -@x * sin_a + @z * cos_a)
    when 'z'
      Vector3D.new(@x * cos_a - @y * sin_a, @x * sin_a + @y * cos_a, @z)
    end
  end
end

class Transformation
  def initialize(translation, rotation, scale)
    @translation = translation
    @rotation = rotation
    @scale = scale
  end

  def apply(vector)
    vector = vector + @translation
    @rotation.each do |axis, angle|
      vector = vector.rotate(angle, axis)
    end
    vector = vector.scale(@scale)
    vector
  end
end

class GeometryTransformer
  def initialize(transformations)
    @transformations = transformations
  end

  def process(initial_vector)
    current_vector = initial_vector
    @transformations.each do |transformation|
      current_vector = transformation.apply(current_vector)
    end
    current_vector
  end
end

def main
  initial_vector = Vector3D.new(1, 0, 0)
  transformations = [
    Transformation.new(Vector3D.new(0, 0, 0), {'x' => 1.57}, 2),
    Transformation.new(Vector3D.new(1, 1, 1), {'y' => 1.57}, 0.5),
    Transformation.new(Vector3D.new(0, 0, 0), {'z' => 1.57}, 1)
  ]
  transformer = GeometryTransformer.new(transformations)
  loop do
    transformed_vector = transformer.process(initial_vector)
    puts "Transformed Vector: (#{transformed_vector.x}, #{transformed_vector.y}, #{transformed_vector.z})"
  end
end

main