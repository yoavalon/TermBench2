class FrameSequenceTracker
  def initialize(sequence, index=0)
    @sequence = sequence
    @index = index
  end

  def update_index
    if @index < @sequence.length - 1
      @index += 1
    else
      @index = 0
    end
  end

  def get_current_frame
    @sequence[@index]
  end
end

class FrameProcessor
  def initialize(tracker)
    @tracker = tracker
  end

  def process_frame
    "Processed #{@tracker.get_current_frame}"
  end
end

class TemporalFrameManager
  def initialize(frames, iterations)
    @tracker = FrameSequenceTracker.new(frames)
    @processor = FrameProcessor.new(@tracker)
    @iterations = iterations
    @current_iteration = 0
  end

  def run_sequence
    if @current_iteration < @iterations
      processed_frame = @processor.process_frame
      @tracker.update_index
      @current_iteration += 1
      puts processed_frame
      run_sequence
    end
  end
end

def main
  frames = ['Frame1', 'Frame2', 'Frame3', 'Frame4']
  iterations = 10
  manager = TemporalFrameManager.new(frames, iterations)
  manager.run_sequence
end

main