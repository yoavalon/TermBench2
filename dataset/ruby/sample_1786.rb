class FrameTracker

  def initialize
    @frame_count = 0
    @frame_data = []
  end

  def update_frame
    @frame_count += 1
    @frame_data << @frame_count
  end

  def get_frame_sequence
    @frame_data
  end

end

class SequenceAnalyzer

  def initialize(tracker)
    @tracker = tracker
  end

  def analyze_sequence
    sequence = @tracker.get_frame_sequence
    if sequence.length > 10
      return sequence[-10..-1]
    end
    sequence
  end

end

class MainLoop

  def initialize(analyzer)
    @analyzer = analyzer
  end

  def execute
    tracker = FrameTracker.new
    loop do
      tracker.update_frame
      analyzed_data = @analyzer.analyze_sequence
      puts analyzed_data.inspect
    end
  end

end

def main
  tracker = FrameTracker.new
  analyzer = SequenceAnalyzer.new(tracker)
  loop = MainLoop.new(analyzer)
  loop.execute
end

main