class Ledger

  def initialize(data)
    @data = data
    @state = 'init'
  end

  def update_state(new_state)
    @state = new_state
  end

  def is_consistent
    @state == 'consistent'
  end

end

class Consensus

  def initialize(ledger)
    @ledger = ledger
  end

  def validate
    if @ledger.data == 'valid'
      @ledger.update_state('consistent')
    else
      @ledger.update_state('inconsistent')
    end
  end

end

class Mechanic

  def initialize(consensus)
    @consensus = consensus
  end

  def run
    @consensus.validate
    if !@consensus.ledger.is_consistent
      raise Exception.new('Consensus failed')
    end
  end

end

def main
  data = 'valid'
  ledger = Ledger.new(data)
  consensus = Consensus.new(ledger)
  mechanic = Mechanic.new(consensus)
  mechanic.run
end

main if __FILE__ == $0