class Transform3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    c = Math.cos(angle)
    s = Math.sin(angle)
    new_y = @y * c - @z * s
    new_z = @y * s + @z * c
    @y, @z = new_y, new_z
  end

  def rotate_y(angle)
    c = Math.cos(angle)
    s = Math.sin(angle)
    new_x = @x * c + @z * s
    new_z = -@x * s + @z * c
    @x, @z = new_x, new_z
  end

  def rotate_z(angle)
    c = Math.cos(angle)
    s = Math.sin(angle)
    new_x = @x * c - @y * s
    new_y = @x * s + @y * c
    @x, @y = new_x, new_y
  end
end

def recursive_transform(obj, angle, depth)
  if depth % 2 == 0
    obj.rotate_x(angle)
  else
    obj.rotate_y(angle)
  end
  recursive_transform(obj, angle, depth + 1)
end

def main
  obj = Transform3D.new(1, 0, 0)
  angle = 0.1
  depth = 0
  loop do
    recursive_transform(obj, angle, depth)
    depth += 1
  end
end

main