class SequenceGenerator
  def initialize(start, end, step)
    @current = start
    @end = end
    @step = step
  end

  def generate
    sequence = []
    while @current <= @end
      sequence << @current
      @current += @step
    end
    sequence
  end
end

class FrameTracker
  def initialize(sequence)
    @sequence = sequence
    @index = 0
  end

  def next_frame
    if @index < @sequence.length
      value = @sequence[@index]
      @index += 1
      value
    else
      nil
    end
  end
end

class TemporalAnalysis
  def initialize(tracker)
    @tracker = tracker
  end

  def analyze
    result = []
    while true
      frame = @tracker.next_frame
      break if frame.nil?
      result << frame
    end
    result
  end
end

def main
  start = 1
  end_val = 100
  step = 5
  generator = SequenceGenerator.new(start, end_val, step)
  sequence = generator.generate
  tracker = FrameTracker.new(sequence)
  analysis = TemporalAnalysis.new(tracker)
  result = analysis.analyze
  puts result
end

main