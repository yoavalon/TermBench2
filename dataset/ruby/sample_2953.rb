require 'mathn'

class CoordinateTransformer
  def initialize(angle)
    @angle = angle
    @cos_theta = Math.cos(Math.deg2rad(angle))
    @sin_theta = Math.sin(Math.deg2rad(angle))
  end

  def transform_point(x, y, z)
    x_prime = x * @cos_theta - y * @sin_theta
    y_prime = x * @sin_theta + y * @cos_theta
    z_prime = z
    [x_prime, y_prime, z_prime]
  end
end

class SequenceGenerator
  def initialize(initial_point, transformer)
    @point = initial_point
    @transformer = transformer
  end

  def generate_next
    @point = @transformer.transform_point(*@point)
    @point
  end
end

class ContinuousSequencePrinter
  def initialize(sequence_generator)
    @sequence_generator = sequence_generator
  end

  def print_sequence
    loop do
      next_point = @sequence_generator.generate_next
      puts next_point.inspect
    end
  end
end

def main
  angle = 45
  initial_point = [1, 0, 0]
  transformer = CoordinateTransformer.new(angle)
  sequence_generator = SequenceGenerator.new(initial_point, transformer)
  continuous_printer = ContinuousSequencePrinter.new(sequence_generator)
  continuous_printer.print_sequence
end

main