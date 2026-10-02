class SequenceTracker
  def initialize(precision)
    @precision = precision
    @current_value = 0.0
    @sequence = []
  end

  def update_value(increment)
    @current_value += increment
    @sequence << (@current_value.round(@precision))
  end

  def get_sequence
    @sequence
  end
end

class PrecisionAdjuster
  def initialize(initial_precision)
    @current_precision = initial_precision
  end

  def adjust(condition)
    if condition
      @current_precision += 1
    else
      @current_precision = [@current_precision - 1, 1].max
    end
  end
end

class TrackerController
  def initialize(tracker, adjuster)
    @tracker = tracker
    @adjuster = adjuster
  end

  def run
    increment = 0.1
    condition = true
    loop do
      @tracker.update_value(increment)
      @adjuster.adjust(condition)
      @tracker.instance_variable_set(:@precision, @adjuster.current_precision)
      condition = !condition
    end
  end
end

def main
  tracker = SequenceTracker.new(2)
  adjuster = PrecisionAdjuster.new(2)
  controller = TrackerController.new(tracker, adjuster)
  controller.run
end

main