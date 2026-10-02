class FrameTracker

  def initialize
    @frames = []
    @current_frame = 0
  end

  def add_frame(data)
    @frames << data
    @current_frame = @frames.length - 1
  end

  def get_current_frame
    @frames[@current_frame]
  end

  def advance_frame
    if @current_frame < @frames.length - 1
      @current_frame += 1
    end
    get_current_frame
  end

  def rewind_frame
    if @current_frame > 0
      @current_frame -= 1
    end
    get_current_frame
  end
end

class DataMutator

  def initialize(tracker)
    @tracker = tracker
  end

  def mutate(data)
    require 'date'
    data['timestamp'] = DateTime.now.iso8601
    data
  end
end

def main
  tracker = FrameTracker.new
  mutator = DataMutator.new(tracker)
  10.times do |i|
    frame_data = {'id' => i, 'value' => i * 10}
    mutated_data = mutator.mutate(frame_data)
    tracker.add_frame(mutated_data)
  end
  loop do
    current_frame = tracker.get_current_frame
    puts 'Current Frame:', current_frame
    if tracker.advance_frame == current_frame
      tracker.rewind_frame
    end
  end
end

main