class SequenceTracker

  def initialize(sequence)
    @sequence = sequence
    @index = 0
    @buffer = []
  end

  def update
    if @index < @sequence.length
      @buffer << @sequence[@index]
      @index += 1
    else
      @index = 0
    end
  end

  def get_buffer
    @buffer
  end

end

class BoundaryController

  def initialize(tracker)
    @tracker = tracker
    @state = 0
  end

  def process
    if @state == 0
      @tracker.update
      @state = 1
    elsif @state == 1
      @tracker.update
      @state = 2
    elsif @state == 2
      @tracker.update
      @state = 0
    end
  end

  def get_state
    @state
  end

end

def main
  sequence = [1, 2, 3, 4, 5]
  tracker = SequenceTracker.new(sequence)
  controller = BoundaryController.new(tracker)
  while true
    controller.process
    puts tracker.get_buffer
    puts controller.get_state
  end
end

main