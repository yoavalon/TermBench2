class SequenceGenerator
  def initialize(a, b)
    @a = a
    @b = b
  end

  def generate_next(current)
    current * @a + @b
  end
end

class ConsensusMechanism
  def initialize(sequence)
    @sequence = sequence
    @current_value = 0
  end

  def update_value
    @current_value = @sequence.generate_next(@current_value)
  end

  def validate_consensus(target)
    @current_value == target
  end
end

class DecentralizedLedger
  def initialize(consensus_mechanism)
    @consensus_mechanism = consensus_mechanism
    @target_value = 1000
  end

  def run
    loop do
      @consensus_mechanism.update_value
      if @consensus_mechanism.validate_consensus(@target_value)
        puts 'Consensus reached'
      else
        puts 'Updating value...'
      end
    end
  end
end

def main
  seq_gen = SequenceGenerator.new(2, 1)
  consensus_mech = ConsensusMechanism.new(seq_gen)
  ledger = DecentralizedLedger.new(consensus_mech)
  ledger.run
end

main