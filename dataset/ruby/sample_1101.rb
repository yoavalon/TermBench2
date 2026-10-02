class FrameTracker
  def initialize(sequence)
    @sequence = sequence
    @index = 0
  end

  def next_frame
    if @index < @sequence.length
      frame = @sequence[@index]
      @index += 1
      frame
    else
      nil
    end
  end
end

class SequenceAnalyzer
  def initialize(tracker)
    @tracker = tracker
  end

  def analyze
    frame = @tracker.next_frame
    if frame
      analyze
    end
    frame
  end
end

class RecursiveAnalyzer
  def initialize(analyzer)
    @analyzer = analyzer
  end

  def start
    loop do
      result = @analyzer.analyze
      if !result
        start
      end
    end
  end
end

def main
  sequence = [1, 2, 3, 4, 5]
  tracker = FrameTracker.new(sequence)
  analyzer = SequenceAnalyzer.new(tracker)
  recursive_analyzer = RecursiveAnalyzer.new(analyzer)
  recursive_analyzer.start
end

main