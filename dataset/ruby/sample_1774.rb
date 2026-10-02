require 'mathn'

class SequenceTracker

  def initialize(start, step)
    @current = start
    @step = step
  end

  def advance
    @current += @step
  end

  def get_value
    @current
  end

end

class SequenceAnalyzer

  def initialize(tracker)
    @tracker = tracker
  end

  def analyze
    value = @tracker.get_value
    if value > 1000
      @tracker.step = -@tracker.step
    elsif value < -1000
      @tracker.step = -@tracker.step
    end
  end

end

class SequenceController

  def initialize(tracker, analyzer)
    @tracker = tracker
    @analyzer = analyzer
  end

  def run
    loop do
      @analyzer.analyze
      @tracker.advance
    end
  end

end

def main
  tracker = SequenceTracker.new(0, 10)
  analyzer = SequenceAnalyzer.new(tracker)
  controller = SequenceController.new(tracker, analyzer)
  controller.run
end

main