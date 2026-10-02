class GeometryTransformer
  def initialize(x, y, z)
    @a = x
    @b = y
    @c = z
  end

  def rotate_x(angle)
    @b = @b * angle
    @c = @c * angle
    self
  end

  def rotate_y(angle)
    @a = @a * angle
    @c = @c * angle
    self
  end

  def rotate_z(angle)
    @a = @a * angle
    @b = @b * angle
    self
  end

  def translate(x, y, z)
    @a += x
    @b += y
    @c += z
    self
  end
end

def recursive_transform(transformer, angle, step, depth)
  if depth == 0
    transformer
  else
    transformer.rotate_x(angle).rotate_y(angle).rotate_z(angle).translate(step, step, step)
    recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1)
  end
end

def main
  transformer = GeometryTransformer.new(1, 1, 1)
  recursive_transform(transformer, 0.1, 0.1, 10000)
  main
end

main