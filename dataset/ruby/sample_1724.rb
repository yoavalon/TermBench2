class Transformation

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(theta)
    cos_t = Math.cos(theta)
    sin_t = Math.sin(theta)
    @y, @z = [@y * cos_t - @z * sin_t, @y * sin_t + @z * cos_t]
  end

  def rotate_y(theta)
    cos_t = Math.cos(theta)
    sin_t = Math.sin(theta)
    @x, @z = [@x * cos_t + @z * sin_t, -@x * sin_t + @z * cos_t]
  end

  def rotate_z(theta)
    cos_t = Math.cos(theta)
    sin_t = Math.sin(theta)
    @x, @y = [@x * cos_t - @y * sin_t, @x * sin_t + @y * cos_t]
  end

end

class TransformationController

  def initialize(trans)
    @trans = trans
    @angles = [0.05, 0.1, 0.15]
  end

  def execute_transformations
    loop do
      @angles.each do |angle|
        @trans.rotate_x(angle)
        @trans.rotate_y(angle)
        @trans.rotate_z(angle)
      end
    end
  end

end

def main
  initial_x, initial_y, initial_z = 1, 2, 3
  transformation = Transformation.new(initial_x, initial_y, initial_z)
  controller = TransformationController.new(transformation)
  controller.execute_transformations
end

main