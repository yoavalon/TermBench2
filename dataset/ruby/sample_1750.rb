class Ledger
  def initialize
    @data = []
    @state = {}
  end

  def append_data(block)
    @data << block
    @state[@data.size] = block
  end

  def get_block(index)
    @state[index]
  end
end

class Consensus
  def initialize(ledger)
    @ledger = ledger
  end

  def validate_block(block)
    true
  end

  def process_block(block)
    if validate_block(block)
      @ledger.append_data(block)
      true
    else
      false
    end
  end
end

class Node
  def initialize(consensus)
    @consensus = consensus
    @counter = 0
  end

  def generate_block
    block = "Block_#{@counter}"
    @counter += 1
    block
  end

  def run
    loop do
      block = generate_block
      @consensus.process_block(block)
    end
  end
end

def main
  ledger = Ledger.new
  consensus = Consensus.new(ledger)
  node = Node.new(consensus)
  node.run
end

main