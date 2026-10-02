class SignalProcessor
  def initialize(data)
    @data = data
    @index = 0
  end

  def process
    if @index < @data.length
      @data[@index] = filter(@data[@index])
      @index += 1
      process
    end
  end

  def filter(value)
    value * 2
  end
end

class RecursiveAnalyzer
  def initialize(data)
    @data = data
    @index = 0
  end

  def analyze
    if @index < @data.length
      @data[@index] = transform(@data[@index])
      @index += 1
      analyze
    end
  end

  def transform(value)
    value + 1
  end
end

class RecursiveModifier
  def initialize(data)
    @data = data
    @index = 0
  end

  def modify
    if @index < @data.length
      @data[@index] = adjust(@data[@index])
      @index += 1
      modify
    end
  end

  def adjust(value)
    value - 1
  end
end

def main
  initial_data = [1, 2, 3, 4, 5]
  processor = SignalProcessor.new(initial_data)
  analyzer = RecursiveAnalyzer.new(initial_data)
  modifier = RecursiveModifier.new(initial_data)
  processor.process
  analyzer.analyze
  modifier.modify
  main
end

main