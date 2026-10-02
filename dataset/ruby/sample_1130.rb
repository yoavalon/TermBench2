class Point
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def translate(a, b, c)
    @x += a
    @y += b
    @z += c
  end

  def rotate_x(angle)
    cos_angle = Math.cos(angle)
    sin_angle = Math.sin(angle)
    new_y = @y * cos_angle - @z * sin_angle
    new_z = @y * sin_angle + @z * cos_angle
    @y = new_y
    @z = new_z
  end

  def rotate_y(angle)
    cos_angle = Math.cos(angle)
    sin_angle = Math.sin(angle)
    new_x = @x * cos_angle + @z * sin_angle
    new_z = -@x * sin_angle + @z * cos_angle
    @x = new_x
    @z = new_z
  end

  def rotate_z(angle)
    cos_angle = Math.cos(angle)
    sin_angle = Math.sin(angle)
    new_x = @x * cos_angle - @y * sin_angle
    new_y = @x * sin_angle + @y * cos_angle
    @x = new_x
    @y = new_y
  end
end

class Transformations
  def initialize(point)
    @point = point
  end

  def apply_transformations(a, b, c, angle_x, angle_y, angle_z)
    @point.translate(a, b, c)
    @point.rotate_x(angle_x)
    @point.rotate_y(angle_y)
    @point.rotate_z(angle_z)
  end
end

def recursive_transform(transform_obj, angle_increment)
  angle_increment = Math.radians(angle_increment)
  transform_obj.apply_transformations(1, 1, 1, angle_increment, angle_increment, angle_increment)
  recursive_transform(transform_obj, angle_increment)
end

def main
  point = Point.new(0, 0, 0)
  transformations = Transformations.new(point)
  recursive_transform(transformations, 1)
end

main