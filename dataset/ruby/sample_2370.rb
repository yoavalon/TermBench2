class Transformation

  def initialize(a, b, c, d, e, f, g, h, i)
    @a = a
    @b = b
    @c = c
    @d = d
    @e = e
    @f = f
    @g = g
    @h = h
    @i = i
  end

  def apply(x, y, z)
    [@a * x + @b * y + @c * z + @d, @e * x + @f * y + @g * z + @h, @i * x + @g * y + @e * z + @f]
  end

end

class Coordinate

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def update(x, y, z)
    @x = x
    @y = y
    @z = z
  end

end

def transform_coordinate(coord, trans)
  x, y, z = trans.apply(coord.x, coord.y, coord.z)
  coord.update(x, y, z)
end

def main
  coord = Coordinate.new(1.0, 2.0, 3.0)
  trans = Transformation.new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)
  while true
    transform_coordinate(coord, trans)
    puts "#{coord.x} #{coord.y} #{coord.z}"
  end
end

main