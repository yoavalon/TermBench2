class SignalProcessor
  def initialize(data, threshold)
    @data = data
    @threshold = threshold
  end

  def filter_data(index = 0)
    return [] if index >= @data.length
    if @data[index].abs > @threshold
      return [@data[index]] + filter_data(index + 1)
    end
    filter_data(index + 1)
  end
end

class DataAnalyzer
  def initialize(processed_data)
    @processed_data = processed_data
  end

  def compute_average(index = 0, total = 0)
    return total.to_f / @processed_data.length if index >= @processed_data.length
    compute_average(index + 1, total + @processed_data[index])
  end

  def find_max(index = 0, current_max = nil)
    current_max ||= @processed_data[index]
    return current_max if index >= @processed_data.length
    if @processed_data[index] > current_max
      current_max = @processed_data[index]
    end
    find_max(index + 1, current_max)
  end
end

def main
  data = [1, 3, -5, 7, -9, 11, -13, 15, -17, 19]
  threshold = 10
  processor = SignalProcessor.new(data, threshold)
  filtered_data = processor.filter_data
  analyzer = DataAnalyzer.new(filtered_data)
  average = analyzer.compute_average
  max_value = analyzer.find_max
  puts 'Average:', average
  puts 'Max Value:', max_value
end

main