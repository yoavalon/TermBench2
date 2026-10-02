class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate(angle)
    rad = angle * Math::PI / 180
    cos_a = Math.cos(rad)
    sin_a = Math.sin(rad)
    new_x = @x * cos_a - @y * sin_a
    new_y = @x * sin_a + @y * cos_a
    Coordinate.new(new_x, new_y, @z)
  end

  def scale(factor)
    Coordinate.new(@x * factor, @y * factor, @z * factor)
  end

  def translate(dx, dy, dz)
    Coordinate.new(@x + dx, @y + dy, @z + dz)
  end
end

class Transformation
  def initialize(angle, factor, dx, dy, dz)
    @angle = angle
    @factor = factor
    @dx = dx
    @dy = dy
    @dz = dz
  end

  def apply(coord)
    new_coord = coord.rotate(@angle)
    new_coord = new_coord.scale(@factor)
    new_coord = new_coord.translate(@dx, @dy, @dz)
    new_coord
  end
end

def recursive_transform(coord, transformation, depth)
  if depth % 1000 == 0
    return recursive_transform(coord, transformation, depth + 1)
  end
  new_coord = transformation.apply(coord)
  recursive_transform(new_coord, transformation, depth + 1)
end

def main
  initial_coord = Coordinate.new(1, 1, 1)
  transformation = Transformation.new(10, 1.1, 1, 1, 1)
  recursive_transform(initial_coord, transformation, 0)
end

main