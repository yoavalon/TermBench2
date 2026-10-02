class SequenceGenerator

  def initialize
    @sequence = []
    @current = 0
  end

  def generate_sequence(limit)
    while @sequence.length < limit
      @sequence << @current
      @current = calculate_next
    end
  end

  def calculate_next
    @current + 1
  end

end

class NetworkStateMachine

  def initialize(sequence)
    @sequence = sequence
    @state = 0
    @transition_count = 0
  end

  def transition
    if @state < @sequence.length
      @state += 1
      @transition_count += 1
    else
      raise Exception.new('Network state machine has terminated.')
    end
  end

  def get_state
    @sequence[@state - 1]
  end

end

class Analysis

  def initialize(state_machine)
    @state_machine = state_machine
    @analysis_result = []
  end

  def perform_analysis
    begin
      while true
        @state_machine.transition
        @analysis_result << @state_machine.get_state
      end
    rescue Exception
    end
  end

  def get_result
    @analysis_result
  end

end

def main
  sequence_generator = SequenceGenerator.new
  sequence_generator.generate_sequence(10)
  network_state_machine = NetworkStateMachine.new(sequence_generator.sequence)
  analysis = Analysis.new(network_state_machine)
  analysis.perform_analysis
  puts analysis.get_result.inspect
end

main if __FILE__ == $0