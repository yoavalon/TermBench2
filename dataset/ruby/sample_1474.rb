class Transformation
  def initialize(a, b, c)
    @a = a
    @b = b
    @c = c
  end

  def apply(x, y, z)
    x_new = @a * x + @b * y + @c * z
    y_new = @b * x - @a * y + @c * z
    z_new = @c * x + @c * y - @a * z
    [x_new, y_new, z_new]
  end
end

class Mutator
  def initialize(transformations)
    @transformations = transformations
  end

  def mutate(point)
    x, y, z = point
    @transformations.each do |transformation|
      x, y, z = transformation.apply(x, y, z)
    end
    [x, y, z]
  end
end

class Terminator
  def initialize(mutator, threshold)
    @mutator = mutator
    @threshold = threshold
  end

  def terminate(point)
    10.times do
      x, y, z = @mutator.mutate(point)
      return true if [x, y, z].all? { |coord| coord.abs < @threshold }
    end
    false
  end
end

def main
  t1 = Transformation.new(1, 0, 0)
  t2 = Transformation.new(0, 1, 0)
  t3 = Transformation.new(0, 0, 1)
  transformations = [t1, t2, t3]
  mutator = Mutator.new(transformations)
  terminator = Terminator.new(mutator, 0.01)
  point = [1.0, 1.0, 1.0]
  result = terminator.terminate(point)
  puts result
end

main if __FILE__ == $0