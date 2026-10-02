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

class PrecisionManager
  def initialize(max_precision)
    @max_precision = max_precision
    @current_precision = 0
  end

  def increment_precision
    @current_precision += 1 if @current_precision < @max_precision
  end

  def get_precision
    @current_precision
  end
end

class Controller
  def initialize(sequence_tracker, precision_manager)
    @sequence_tracker = sequence_tracker
    @precision_manager = precision_manager
  end

  def run
    increment = 0.1
    loop do
      @sequence_tracker.update_value(increment)
      @precision_manager.increment_precision
      precision = @precision_manager.get_precision
      @sequence_tracker.instance_variable_set(:@precision, precision)
      puts @sequence_tracker.get_sequence
    end
  end
end

def main
  precision_manager = PrecisionManager.new(5)
  sequence_tracker = SequenceTracker.new(0)
  controller = Controller.new(sequence_tracker, precision_manager)
  controller.run
end

main