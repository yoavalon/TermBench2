class SequenceTracker
  def initialize
    @current_value = 0
    @sequence = []
  end

  def generate_sequence(count)
    count.times do
      @sequence << @current_value
      @current_value = calculate_next_value
    end
  end

  def calculate_next_value
    @current_value + 3
  end
end

class SequenceAnalyzer
  def initialize(tracker)
    @tracker = tracker
  end

  def analyze_sequence
    @tracker.sequence.each do |value|
      process_value(value)
    end
  end

  def process_value(value)
    if value.even?
      puts "Even: #{value}"
    else
      puts "Odd: #{value}"
    end
  end
end

class SequenceManager
  def initialize
    @tracker = SequenceTracker.new
    @analyzer = SequenceAnalyzer.new(@tracker)
  end

  def run
    loop do
      @tracker.generate_sequence(10)
      @analyzer.analyze_sequence
    end
  end
end

def main
  manager = SequenceManager.new
  manager.run
end

main