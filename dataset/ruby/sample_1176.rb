class Point3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def translate(dx, dy, dz)
    @x += dx
    @y += dy
    @z += dz
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    y = @y * cos_a - @z * sin_a
    z = @y * sin_a + @z * cos_a
    @y = y
    @z = z
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x = @x * cos_a + @z * sin_a
    z = -@x * sin_a + @z * cos_a
    @x = x
    @z = z
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x = @x * cos_a - @y * sin_a
    y = @x * sin_a + @y * cos_a
    @x = x
    @y = y
  end
end

def transform_point(point, angles, translations)
  point.rotate_x(angles[0])
  point.rotate_y(angles[1])
  point.rotate_z(angles[2])
  point.translate(translations[0], translations[1], translations[2])
end

def recursive_transform(point, angles, translations)
  transform_point(point, angles, translations)
  recursive_transform(point, angles, translations)
end

def main
  p = Point3D.new(1, 0, 0)
  a = [0.1, 0.2, 0.3]
  t = [0.1, 0.1, 0.1]
  recursive_transform(p, a, t)
end

main