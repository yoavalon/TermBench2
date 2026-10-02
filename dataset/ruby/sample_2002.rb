class Transform3D

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_y = @y * cos_a - @z * sin_a
    new_z = @y * sin_a + @z * cos_a
    Transform3D.new(@x, new_y, new_z)
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_x = @x * cos_a + @z * sin_a
    new_z = -@x * sin_a + @z * cos_a
    Transform3D.new(new_x, @y, new_z)
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_x = @x * cos_a - @y * sin_a
    new_y = @x * sin_a + @y * cos_a
    Transform3D.new(new_x, new_y, @z)
  end

end

class TransformHandler

  def initialize(points)
    @points = points.map { |point| Transform3D.new(*point) }
  end

  def apply_rotation(angle_x, angle_y, angle_z)
    rotated_points = []
    @points.each do |point|
      rotated = point.rotate_x(angle_x).rotate_y(angle_y).rotate_z(angle_z)
      rotated_points << [rotated.x, rotated.y, rotated.z]
    end
    rotated_points
  end

end

def main
  initial_points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  handler = TransformHandler.new(initial_points)
  angles = [Math::PI / 4, Math::PI / 4, Math::PI / 4]
  result = handler.apply_rotation(*angles)
  result.each { |point| puts point.inspect }
end

main