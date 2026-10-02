require 'mathn'

class CoordinateTransformer
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_y = @y * cos_a - @z * sin_a
    new_z = @y * sin_a + @z * cos_a
    @y, @z = new_y, new_z
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_x = @x * cos_a + @z * sin_a
    new_z = -@x * sin_a + @z * cos_a
    @x, @z = new_x, new_z
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_x = @x * cos_a - @y * sin_a
    new_y = @x * sin_a + @y * cos_a
    @x, @y = new_x, new_y
  end

  def scale(factor)
    @x *= factor
    @y *= factor
    @z *= factor
  end
end

def generate_angles
  angle = 0
  loop do
    yield angle
    angle += Math::PI / 180
  end
end

def transform_sequence(transformer, angles)
  angles.each do |angle|
    transformer.rotate_x(angle)
    transformer.rotate_y(angle)
    transformer.rotate_z(angle)
    transformer.scale(1.01)
  end
end

def main
  transformer = CoordinateTransformer.new(1, 0, 0)
  angles = generate_angles
  transform_sequence(transformer, angles)
end

main