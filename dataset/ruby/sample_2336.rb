class SequenceTracker

  def initialize
    @state = 0.0
    @frame_count = 0
  end

  def update(increment)
    @state += increment
    @frame_count += 1
  end

  def reset
    @state = 0.0
    @frame_count = 0
  end

end

class FrameProcessor

  def initialize(tracker)
    @tracker = tracker
  end

  def process_frame(data)
    @tracker.update(data)
  end

end

class Controller

  def initialize(processor)
    @processor = processor
    @threshold = 1000.0
  end

  def run
    loop do
      data = generate_data
      @processor.process_frame(data)
      if @processor.tracker.state > @threshold
        @processor.tracker.reset
      end
    end
  end

  def generate_data
    0.1
  end

end

def main
  tracker = SequenceTracker.new
  processor = FrameProcessor.new(tracker)
  controller = Controller.new(processor)
  controller.run
end

main