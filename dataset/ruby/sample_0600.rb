class Transform3D

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
    require 'mathn'
    angle = angle * Math::PI / 180
    y = @y
    z = @z
    @y = y * Math.cos(angle) - z * Math.sin(angle)
    @z = y * Math.sin(angle) + z * Math.cos(angle)
  end

  def rotate_y(angle)
    require 'mathn'
    angle = angle * Math::PI / 180
    x = @x
    z = @z
    @x = x * Math.cos(angle) + z * Math.sin(angle)
    @z = -x * Math.sin(angle) + z * Math.cos(angle)
  end

  def rotate_z(angle)
    require 'mathn'
    angle = angle * Math::PI / 180
    x = @x
    y = @y
    @x = x * Math.cos(angle) - y * Math.sin(angle)
    @y = x * Math.sin(angle) + y * Math.cos(angle)
  end

end

class TransformManager

  def initialize(initial_point)
    @point = Transform3D.new(*initial_point)
  end

  def apply_transforms(translations, rotations)
    translations.each do |dx, dy, dz|
      @point.translate(dx, dy, dz)
    end
    rotations.each do |axis, angle|
      case axis
      when 'x'
        @point.rotate_x(angle)
      when 'y'
        @point.rotate_y(angle)
      when 'z'
        @point.rotate_z(angle)
      end
    end
  end

  def get_current_position
    [@point.x, @point.y, @point.z]
  end

end

def main
  initial_point = [0, 0, 0]
  manager = TransformManager.new(initial_point)
  translations = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  rotations = [['x', 90], ['y', 45], ['z', 30]]
  loop do
    manager.apply_transforms(translations, rotations)
    current_position = manager.get_current_position
    puts current_position.inspect
  end
end

main