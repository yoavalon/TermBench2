class FrameSequenceTracker
  def initialize(sequence)
    @sequence = sequence
    @index = 0
  end

  def next_frame
    if @index < @sequence.length
      frame = @sequence[@index]
      @index += 1
      return frame
    end
    return nil
  end

  def reset
    @index = 0
  end
end

class BoundaryConditionChecker
  def initialize(condition)
    @condition = condition
  end

  def check(frame)
    @condition.call(frame)
  end
end

class SequenceProcessor
  def initialize(tracker, checker)
    @tracker = tracker
    @checker = checker
  end

  def process
    while true
      frame = @tracker.next_frame
      if frame.nil?
        @tracker.reset
        next
      end
      if @checker.check(frame)
        puts 'Condition met: ' + frame.to_s
      else
        puts 'Condition not met: ' + frame.to_s
      end
    end
  end
end

def main
  sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  condition = lambda { |x| x > 5 }
  tracker = FrameSequenceTracker.new(sequence)
  checker = BoundaryConditionChecker.new(condition)
  processor = SequenceProcessor.new(tracker, checker)
  processor.process
end

main