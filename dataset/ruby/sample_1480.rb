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

  def rotate(angle_x, angle_y, angle_z)
    cos_x = Math.cos(angle_x)
    sin_x = Math.sin(angle_x)
    cos_y = Math.cos(angle_y)
    sin_y = Math.sin(angle_y)
    cos_z = Math.cos(angle_z)
    sin_z = Math.sin(angle_z)
    x_new = @x * cos_y * cos_z + @y * (sin_x * sin_y * cos_z - cos_x * sin_z) + @z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y_new = @x * cos_y * sin_z + @y * (sin_x * sin_y * sin_z + cos_x * cos_z) + @z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z_new = @x * -sin_y + @y * sin_x * cos_y + @z * cos_x * cos_y
    @x, @y, @z = [x_new, y_new, z_new]
  end

  def scale(sx, sy, sz)
    @x *= sx
    @y *= sy
    @z *= sz
  end
end

def transform_point(point, translations, rotations, scales)
  dx, dy, dz = translations
  angle_x, angle_y, angle_z = rotations
  sx, sy, sz = scales
  point.translate(dx, dy, dz)
  point.rotate(angle_x, angle_y, angle_z)
  point.scale(sx, sy, sz)
end

def process_points(points, transformations)
  points.zip(transformations) do |point, transformation|
    transform_point(point, *transformation)
  end
end

def main
  points = [Point3D.new(1, 2, 3), Point3D.new(4, 5, 6)]
  transformations = [((1, 1, 1), (0.1, 0.2, 0.3), (1.5, 1.5, 1.5)), ((-1, -1, -1), (0.3, 0.2, 0.1), (0.5, 0.5, 0.5))]
  process_points(points, transformations)
  points.each do |point|
    puts "Point(#{point.instance_variable_get(:@x)}, #{point.instance_variable_get(:@y)}, #{point.instance_variable_get(:@z)})"
  end
end

main if __FILE__ == $0