class SequenceTracker
  def initialize(initial_value, increment, max_iterations)
    @value = initial_value
    @increment = increment
    @max_iterations = max_iterations
    @current_iteration = 0
  end

  def next
    if @current_iteration < @max_iterations
      @value += @increment
      @current_iteration += 1
      @value
    else
      nil
    end
  end
end

def monitor_sequence(tracker, observer)
  loop do
    result = tracker.next
    if result.nil?
      observer.complete
      break
    else
      observer.on_next(result)
    end
  end
end

class SequenceObserver
  def initialize
    @completed = false
  end

  def on_next(value)
    puts "Current value: #{value}"
  end

  def complete
    puts 'Sequence tracking completed.'
  end
end

def main
  tracker = SequenceTracker.new(0, 1, 10)
  observer = SequenceObserver.new
  monitor_sequence(tracker, observer)
end

main