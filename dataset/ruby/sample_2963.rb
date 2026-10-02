class Transformer

  def initialize
    @matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  end

  def apply_transformation(point)
    x, y, z = point
    new_x = @matrix[0][0] * x + @matrix[0][1] * y + @matrix[0][2] * z
    new_y = @matrix[1][0] * x + @matrix[1][1] * y + @matrix[1][2] * z
    new_z = @matrix[2][0] * x + @matrix[2][1] * y + @matrix[2][2] * z
    [new_x, new_y, new_z]
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    @matrix = [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]]
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    @matrix = [[cos_a, 0, sin_a], [0, 1, 0], [-sin_a, 0, cos_a]]
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    @matrix = [[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]]
  end

end

class SequenceGenerator

  def initialize(transformer)
    @transformer = transformer
    @current_point = [1, 0, 0]
  end

  def generate_sequence
    loop do
      yield @current_point
      @current_point = @transformer.apply_transformation(@current_point)
    end
  end

end

def main
  transformer = Transformer.new
  transformer.rotate_x(0.1)
  transformer.rotate_y(0.1)
  transformer.rotate_z(0.1)
  generator = SequenceGenerator.new(transformer)
  generator.generate_sequence do |point|
    puts point.inspect
  end
end

main