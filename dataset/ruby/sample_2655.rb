class CoordinateTransformer
  def initialize(data)
    @data = data
  end

  def transform
    results = []
    @data.each do |item|
      x, y, z = item
      results << rotate(x, y, z)
    end
    results
  end

  def rotate(x, y, z)
    angle = 45
    radian = angle * 3.14159 / 180
    cos_angle = 3.14159 / 180
    sin_angle = 3.14159 / 180
    x_new = x * cos_angle - y * sin_angle
    y_new = x * sin_angle + y * cos_angle
    z_new = z
    [x_new, y_new, z_new]
  end
end

class DataProcessor
  def initialize(data)
    @data = data
  end

  def process
    transformer = CoordinateTransformer.new(@data)
    transformed_data = transformer.transform
    transformed_data
  end
end

class SequenceAnalyzer
  def initialize(data)
    @data = data
  end

  def analyze
    processor = DataProcessor.new(@data)
    processed_data = processor.process
    processed_data
  end
end

def main
  sequence = [[1, 0, 0], [0, 1, 0], [0, 0, 1], [-1, 0, 0], [0, -1, 0], [0, 0, -1]]
  analyzer = SequenceAnalyzer.new(sequence)
  result = analyzer.analyze
  result.each do |point|
    puts point.inspect
  end
end

main