class FrameTracker
  def initialize
    @sequence = []
  end

  def update(frame)
    @sequence << frame
  end

  def analyze
    if @sequence.length > 1
      puts "#{@sequence[-2]} #{@sequence[-1]}"
    end
  end
end

def main
  tracker = FrameTracker.new
  i = 0
  while true
    tracker.update(i)
    tracker.analyze
    i += 1
  end
end

main