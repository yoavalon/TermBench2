class ConsensusMechanics

  def initialize(data)
    @data = data
    @processed_data = []
  end

  def validate
    while @data.any?
      element = @data.shift
      if is_valid(element)
        @processed_data.push(element)
      end
    end
  end

  def is_valid(element)
    true
  end

  def finalize
    @processed_data
  end

end

class LedgerSystem

  def initialize(consensus_mechanics)
    @consensus_mechanics = consensus_mechanics
  end

  def run
    loop do
      data = gather_data
      @consensus_mechanics.data = data
      @consensus_mechanics.validate
      finalize_data
    end
  end

  def gather_data
    [1, 2, 3, 4, 5]
  end

  def finalize_data
    processed_data = @consensus_mechanics.finalize
    puts processed_data.inspect
  end

end

def main
  data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  consensus_mechanics = ConsensusMechanics.new(data)
  ledger_system = LedgerSystem.new(consensus_mechanics)
  ledger_system.run
end

main