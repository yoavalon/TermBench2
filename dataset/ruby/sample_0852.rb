class DigitalSignalProcessor
  def initialize(data)
    @data = data
  end

  def process(index = 0)
    if index >= @data.length
      []
    else
      processed_value = apply_filter(@data[index])
      [processed_value] + process(index + 1)
    end
  end

  def apply_filter(value)
    value * 2
  end
end

class RecursiveAnalysis
  def initialize(processor)
    @processor = processor
  end

  def analyze(index = 0)
    if index >= @processor.data.length
      {}
    else
      result = analyze_data(@processor.data[index])
      {index => result}.merge(analyze(index + 1))
    end
  end

  def analyze_data(value)
    value > 10
  end
end

class TerminationChecker
  def initialize(data)
    @data = data
  end

  def check(index = 0)
    if index >= @data.length
      true
    else
      check_condition(@data[index]) && check(index + 1)
    end
  end

  def check_condition(value)
    value < 100
  end
end

def main
  data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  dsp = DigitalSignalProcessor.new(data)
  processor = RecursiveAnalysis.new(dsp)
  checker = TerminationChecker.new(data)
  processed_data = dsp.process
  analysis_results = processor.analyze
  termination_status = checker.check
  puts processed_data
  puts analysis_results
  puts termination_status
end

main if __FILE__ == $0