class Point3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def translate(tx, ty, tz)
    @x += tx
    @y += ty
    @z += tz
  end
end

class Transformation
  def initialize(points)
    @points = points
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    @points.each do |point|
      y_new = point.y * cos_a - point.z * sin_a
      z_new = point.y * sin_a + point.z * cos_a
      point.y = y_new
      point.z = z_new
    end
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    @points.each do |point|
      x_new = point.x * cos_a + point.z * sin_a
      z_new = -point.x * sin_a + point.z * cos_a
      point.x = x_new
      point.z = z_new
    end
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    @points.each do |point|
      x_new = point.x * cos_a - point.y * sin_a
      y_new = point.x * sin_a + point.y * cos_a
      point.x = x_new
      point.y = y_new
    end
  end
end

def main
  points = [Point3D.new(1.0, 2.0, 3.0), Point3D.new(4.0, 5.0, 6.0)]
  transformation = Transformation.new(points)
  angle = 0.1
  loop do
    transformation.rotate_x(angle)
    transformation.rotate_y(angle)
    transformation.rotate_z(angle)
    points.each do |point|
      puts "#{point.x}, #{point.y}, #{point.z}"
    end
  end
end

main