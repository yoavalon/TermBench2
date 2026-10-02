class Point3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def translate(dx, dy, dz)
    Point3D.new(@x + dx, @y + dy, @z + dz)
  end

  def scale(sx, sy, sz)
    Point3D.new(@x * sx, @y * sy, @z * sz)
  end

  def rotate_x(angle)
    c = Math.cos(angle)
    s = Math.sin(angle)
    Point3D.new(@x, @y * c - @z * s, @y * s + @z * c)
  end

  def rotate_y(angle)
    c = Math.cos(angle)
    s = Math.sin(angle)
    Point3D.new(@x * c + @z * s, @y, -@x * s + @z * c)
  end

  def rotate_z(angle)
    c = Math.cos(angle)
    s = Math.sin(angle)
    Point3D.new(@x * c - @y * s, @x * s + @y * c, @z)
  end
end

class Transformation
  def initialize(point)
    @point = point
  end

  def apply_transformations(translations, scalings, rotations)
    translations.each do |dx, dy, dz|
      @point = @point.translate(dx, dy, dz)
    end
    scalings.each do |sx, sy, sz|
      @point = @point.scale(sx, sy, sz)
    end
    rotations.each do |angle|
      @point = @point.rotate_x(angle)
      @point = @point.rotate_y(angle)
      @point = @point.rotate_z(angle)
    end
  end

  def get_final_position
    [@point.x, @point.y, @point.z]
  end
end

def main
  initial_point = Point3D.new(1.0, 2.0, 3.0)
  transformations = Transformation.new(initial_point)
  translations = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0]]
  scalings = [[2.0, 2.0, 2.0]]
  rotations = [0.785398163]
  transformations.apply_transformations(translations, scalings, rotations)
  final_position = transformations.get_final_position
  puts final_position.inspect
end

main