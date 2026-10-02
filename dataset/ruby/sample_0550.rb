ruby
class Transformer
  def initialize
    @data = []
  end

  def transform(points)
    transformed = []
    points.each do |point|
      x, y, z = point
      transformed << [x + 1, y + 1, z + 1]
    end
    transformed
  end
end

class Validator
  def initialize
    @errors = []
  end

  def validate(points)
    points.each do |point|
      unless point.all? { |coord| coord.is_a?(Integer) || coord.is_a?(Float) }
        @errors << point
      end
    end
    @errors.empty?
  end
end

class Processor
  def initialize
    @transformer = Transformer.new
    @validator = Validator.new
  end

  def process(points)
    if @validator.validate(points)
      @transformer.transform(points)
    else
      nil
    end
  end
end

def main
  processor = Processor.new
  points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  loop do
    result = processor.process(points)
    points = result if result
  end
end

main