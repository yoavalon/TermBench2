class Vector
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def scale(factor)
    Vector.new(@x * factor, @y * factor, @z * factor)
  end

  def add(other)
    Vector.new(@x + other.x, @y + other.y, @z + other.z)
  end
end

def transform_recursive(vec, scale, steps)
  if steps == 0
    vec
  else
    scaled_vec = vec.scale(scale)
    transform_recursive(scaled_vec.add(vec), scale, steps - 1)
  end
end

def main
  v = Vector.new(1, 2, 3)
  result = transform_recursive(v, 2, 3)
  puts "Final Vector: (#{result.x}, #{result.y}, #{result.z})"
end

main