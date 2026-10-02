class Transform3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    y_new = @y * cos_a - @z * sin_a
    z_new = @y * sin_a + @z * cos_a
    @y, @z = y_new, z_new
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x_new = @x * cos_a + @z * sin_a
    z_new = -@x * sin_a + @z * cos_a
    @x, @z = x_new, z_new
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x_new = @x * cos_a - @y * sin_a
    y_new = @x * sin_a + @y * cos_a
    @x, @y = x_new, y_new
  end
end

class TransformationManager
  def initialize
    @transforms = []
  end

  def add_transform(transform)
    @transforms << transform
  end

  def apply_all_transforms(angle)
    @transforms.each do |transform|
      transform.rotate_x(angle)
      transform.rotate_y(angle)
      transform.rotate_z(angle)
    end
  end
end

def main
  manager = TransformationManager.new
  manager.add_transform(Transform3D.new(1.0, 2.0, 3.0))
  manager.add_transform(Transform3D.new(4.0, 5.0, 6.0))
  angle = 0.1
  loop do
    manager.apply_all_transforms(angle)
    angle += 0.01
  end
end

main