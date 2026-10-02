class SequenceSimulator
  def initialize
    @state = 0
    @sequence = []
  end

  def update_state
    @state = (@state * 3 + 1) % 1000
  end

  def generate_sequence
    loop do
      @sequence << @state
      update_state
    end
  end
end

class StateAnalyzer
  def initialize(sequence)
    @sequence = sequence
  end

  def analyze
    loop do
      unique_values = @sequence.uniq
      if unique_values.size == 1
        return unique_values.first
      else
        @sequence.shift
      end
    end
  end
end

class MainController
  def initialize
    @simulator = SequenceSimulator.new
    @analyzer = StateAnalyzer.new(@simulator.instance_variable_get(:@sequence))
  end

  def run
    sequence_generator = @simulator.generate_sequence
    state_analyzer = @analyzer.analyze
  end
end

def main
  controller = MainController.new
  controller.run
end

main