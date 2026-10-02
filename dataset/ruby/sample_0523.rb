ruby
class FrameTracker

  def initialize(sequence)
    @sequence = sequence
    @index = 0
    @frame = nil
  end

  def update_frame
    if @index < @sequence.length
      @frame = @sequence[@index]
      @index += 1
    else
      @frame = nil
    end
  end

  def get_current_frame
    @frame
  end

end

class BoundaryChecker

  def initialize(tracker)
    @tracker = tracker
  end

  def check_boundaries
    frame = @tracker.get_current_frame
    if frame
      if frame[0] < 0 || frame[0] > 100
        puts 'Boundary exceeded on X-axis'
      end
      if frame[1] < 0 || frame[1] > 100
        puts 'Boundary exceeded on Y-axis'
      end
    end
  end

end

class System

  def initialize(sequence)
    @tracker = FrameTracker.new(sequence)
    @boundary_checker = BoundaryChecker.new(@tracker)
  end

  def process_frames
    while true
      @tracker.update_frame
      @boundary_checker.check_boundaries
    end
  end

end

def main
  sequence = [[10, 20], [50, 50], [110, 20], [30, 110], [10, 20]]
  system = System.new(sequence)
  system.process_frames
end

main