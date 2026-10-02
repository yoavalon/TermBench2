class FrameTracker
  def initialize(initial_frame)
    @current_frame = initial_frame
    @next_frame = calculate_next_frame(initial_frame)
  end

  def calculate_next_frame(frame)
    frame + 1
  end

  def update_frame
    @current_frame = @next_frame
    @next_frame = calculate_next_frame(@current_frame)
  end
end

class SequenceAnalyzer
  def initialize(tracker)
    @tracker = tracker
    @analyzed_data = []
  end

  def analyze_sequence
    data_point = gather_data
    @analyzed_data << data_point
    @tracker.update_frame
  end

  def gather_data
    @tracker.current_frame
  end
end

class RecursionEngine
  def initialize(analyzer)
    @analyzer = analyzer
  end

  def run
    @analyzer.analyze_sequence
    run
  end
end

def main
  initial_frame = 0
  frame_tracker = FrameTracker.new(initial_frame)
  sequence_analyzer = SequenceAnalyzer.new(frame_tracker)
  recursion_engine = RecursionEngine.new(sequence_analyzer)
  recursion_engine.run
end

main