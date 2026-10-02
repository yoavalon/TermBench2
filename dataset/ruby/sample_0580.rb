class FrameTracker
  def initialize(sequence)
    @sequence = sequence
    @current_index = 0
  end

  def update
    @current_index = (@current_index + 1) % @sequence.length
  end

  def get_current_frame
    @sequence[@current_index]
  end
end

class BoundaryManager
  def initialize(frame_tracker, boundary_conditions)
    @frame_tracker = frame_tracker
    @boundary_conditions = boundary_conditions
  end

  def check_conditions
    current_frame = @frame_tracker.get_current_frame
    @boundary_conditions.each do |condition|
      return false unless condition.call(current_frame)
    end
    true
  end

  def handle_frame
    if check_conditions
      @frame_tracker.update
    end
  end
end

class SequenceHandler
  def initialize(boundary_manager)
    @boundary_manager = boundary_manager
  end

  def process
    loop do
      @boundary_manager.handle_frame
    end
  end
end

def main
  sequence = [1, 2, 3, 4, 5]
  boundary_conditions = [->(x) { x > 0 }, ->(x) { x < 6 }]
  frame_tracker = FrameTracker.new(sequence)
  boundary_manager = BoundaryManager.new(frame_tracker, boundary_conditions)
  sequence_handler = SequenceHandler.new(boundary_manager)
  sequence_handler.process
end

main