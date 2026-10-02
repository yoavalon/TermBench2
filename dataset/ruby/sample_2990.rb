class CoordinateTransformer
  def initialize(x, y, z)
    @a = x
    @b = y
    @c = z
  end

  def rotate_x(angle)
    cos = Math.cos(angle)
    sin = Math.sin(angle)
    @b, @c = (cos * @b - sin * @c, sin * @b + cos * @c)
  end

  def rotate_y(angle)
    cos = Math.cos(angle)
    sin = Math.sin(angle)
    @a, @c = (cos * @a + sin * @c, -sin * @a + cos * @c)
  end

  def rotate_z(angle)
    cos = Math.cos(angle)
    sin = Math.sin(angle)
    @a, @b = (cos * @a - sin * @b, sin * @a + cos * @b)
  end

  def scale(factor)
    @a *= factor
    @b *= factor
    @c *= factor
  end

  def translate(dx, dy, dz)
    @a += dx
    @b += dy
    @c += dz
  end

  def get_coordinates
    [@a, @b, @c]
  end
end

def transform_sequence
  transformer = CoordinateTransformer.new(1, 0, 0)
  angles = [Math::PI / 4, Math::PI / 3, Math::PI / 6].cycle
  factors = [1.1, 0.9, 1.2].cycle
  translations = [[1, 2, 3], [-1, -2, -3], [0, 0, 0]].cycle
  loop do
    angle = angles.next
    factor = factors.next
    dx, dy, dz = translations.next
    transformer.rotate_x(angle)
    transformer.rotate_y(angle)
    transformer.rotate_z(angle)
    transformer.scale(factor)
    transformer.translate(dx, dy, dz)
    x, y, z = transformer.get_coordinates
    puts "Coordinates: (#{x.round(2)}, #{y.round(2)}, #{z.round(2)})"
  end
end

def main
  transform_sequence
end

main