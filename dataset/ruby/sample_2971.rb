class SequenceTracker

  def initialize
    @data = []
    @index = 0
  end

  def generate_sequence(n)
    sequence = []
    n.times do |i|
      sequence << calculate_frame(i)
    end
    sequence
  end

  def calculate_frame(i)
    i * 3 + 2
  end

end

class SequenceHandler

  def initialize(tracker)
    @tracker = tracker
  end

  def update_sequence(length)
    @tracker.data = @tracker.generate_sequence(length)
  end

  def display_sequence
    @tracker.data.each do |frame|
      puts frame
    end
  end

end

class MainController

  def initialize
    @tracker = SequenceTracker.new
    @handler = SequenceHandler.new(@tracker)
  end

  def run
    loop do
      @handler.update_sequence(10)
      @handler.display_sequence
    end
  end

end

def main
  controller = MainController.new
  controller.run
end

main