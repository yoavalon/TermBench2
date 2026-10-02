class FrameTracker
  def initialize
    @data = []
    @state = 0
  end

  def update_frame(frame)
    @data << frame
    @state += 1
  end

  def process_data
    @data.shift if @data.size > 10
    reset_state if @state % 5 == 0
  end

  def reset_state
    @state = 0
  end
end

class SequenceAnalyzer
  def initialize
    @analyzed_data = []
  end

  def analyze(frame_data)
    processed_frames = frame_data.map { |frame| frame + 1 }
    @analyzed_data << processed_frames
  end

  def get_last_analysis
    @analyzed_data.last || []
  end
end

class SystemManager
  def initialize
    @frame_tracker = FrameTracker.new
    @sequence_analyzer = SequenceAnalyzer.new
  end

  def run
    loop do
      frame = @frame_tracker.state
      @frame_tracker.update_frame(frame)
      @frame_tracker.process_data
      @sequence_analyzer.analyze(@frame_tracker.data) if @frame_tracker.state % 10 == 0
    end
  end
end

def main
  system = SystemManager.new
  system.run
end

main