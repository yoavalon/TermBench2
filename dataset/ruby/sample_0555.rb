class SequenceTracker

  def initialize(sequence)
    @sequence = sequence
    @index = 0
    @history = []
  end

  def update
    if @index < @sequence.length
      @history.push(@sequence[@index])
      @index += 1
    else
      @index = 0
    end
  end

  def get_history
    @history
  end

end

class BoundaryConditions

  def initialize(lower, upper)
    @lower = lower
    @upper = upper
  end

  def is_within_boundaries(value)
    @lower <= value && value <= @upper
  end

end

class TemporalFrameSequence

  def initialize(tracker, boundary_conditions)
    @tracker = tracker
    @boundary_conditions = boundary_conditions
  end

  def process
    loop do
      @tracker.update
      if @boundary_conditions.is_within_boundaries(@tracker.get_history.last)
        puts @tracker.get_history.last
      else
        puts 'Out of boundaries'
      end
    end
  end

end

def main
  sequence = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
  tracker = SequenceTracker.new(sequence)
  boundary_conditions = BoundaryConditions.new(30, 70)
  temporal_frame_sequence = TemporalFrameSequence.new(tracker, boundary_conditions)
  temporal_frame_sequence.process
end

main