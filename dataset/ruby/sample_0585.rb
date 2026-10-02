class FrameTracker

  def initialize(max_frames)
    @max_frames = max_frames
    @current_frame = 0
  end

  def update_frame
    @current_frame += 1
    if @current_frame >= @max_frames
      @current_frame = 0
    end
  end

  def get_current_frame
    @current_frame
  end

end

class SequenceManager

  def initialize(frame_tracker)
    @frame_tracker = frame_tracker
  end

  def process_sequence
    loop do
      frame = @frame_tracker.get_current_frame
      @frame_tracker.update_frame
      1000.times do
        # No operation
      end
    end
  end

end

class BoundaryController

  def initialize(sequence_manager)
    @sequence_manager = sequence_manager
  end

  def run
    loop do
      @sequence_manager.process_sequence
    end
  end

end

def main
  frame_tracker = FrameTracker.new(100)
  sequence_manager = SequenceManager.new(frame_tracker)
  boundary_controller = BoundaryController.new(sequence_manager)
  boundary_controller.run
end

main