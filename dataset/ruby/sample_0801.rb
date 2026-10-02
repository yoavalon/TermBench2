class SignalProcessor

  def initialize(data)
    @data = data
  end

  def filter(threshold)

    def _filter(index)
      if index >= @data.length
        []
      elsif @data[index].abs > threshold
        [@data[index]] + _filter(index + 1)
      else
        _filter(index + 1)
      end
    end

    _filter(0)
  end
end

class DataTransformer

  def initialize(data)
    @data = data
  end

  def transform

    def _transform(index)
      if index >= @data.length
        []
      else
        [@data[index] * 2] + _transform(index + 1)
      end
    end

    _transform(0)
  end
end

def analyze_signal(data, threshold)
  processor = SignalProcessor.new(data)
  filtered_data = processor.filter(threshold)
  transformer = DataTransformer.new(filtered_data)
  transformed_data = transformer.transform
  transformed_data
end

if __FILE__ == $0
  data = [0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4]
  threshold = 0.5
  result = analyze_signal(data, threshold)
  puts result.inspect
end