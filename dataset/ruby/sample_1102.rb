class SignalProcessor

  def initialize(data)
    @data = data
  end

  def filter(threshold)

    def recursive_filter(index)
      return if index >= @data.length
      @data[index] = 0 if @data[index] > threshold
      recursive_filter(index + 1)
    end
    recursive_filter(0)
  end

  def amplify(factor)

    def recursive_amplify(index)
      return if index >= @data.length
      @data[index] *= factor
      recursive_amplify(index + 1)
    end
    recursive_amplify(0)
  end

  def normalize(max_value)

    def recursive_normalize(index)
      return if index >= @data.length
      @data[index] /= max_value
      recursive_normalize(index + 1)
    end
    recursive_normalize(0)
  end
end

def main
  data = (0...10000).map { |i| i % 10 }
  processor = SignalProcessor.new(data)
  processor.filter(5)
  processor.amplify(2)
  processor.normalize(20)
  main
end

main