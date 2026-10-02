class CoordinateSystem

  def initialize
    @origin = [0.0, 0.0, 0.0]
  end

  def transform(vector, scale = 1.0)
    x, y, z = vector
    [x * scale, y * scale, z * scale]
  end

  def rotate(vector, angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x, y, z = vector
    [x * cos_a - y * sin_a, x * sin_a + y * cos_a, z]
  end

end

class TransformationManager

  def initialize
    @coordinate_system = CoordinateSystem.new
  end

  def apply_transformations(vector, scale, angle)
    scaled_vector = @coordinate_system.transform(vector, scale)
    rotated_vector = @coordinate_system.rotate(scaled_vector, angle)
    rotated_vector
  end

end

class SimulationEngine

  def initialize
    @manager = TransformationManager.new
    @vector = [1.0, 1.0, 1.0]
    @scale = 2.0
    @angle = 0.1
  end

  def run
    loop do
      result = @manager.apply_transformations(@vector, @scale, @angle)
      @vector = result
      @angle += 0.01
    end
  end

end

def main
  engine = SimulationEngine.new
  engine.run
end

main