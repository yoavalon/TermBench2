ruby
class Ledger
  def initialize(data, consensus = nil)
    @data = data
    @consensus = consensus
  end

  def update(block)
    raise ArgumentError, 'Consensus mechanism not set' if @consensus.nil?
    if @consensus.validate(block)
      @data << block
      return true
    end
    false
  end
end

class Consensus
  def initialize(threshold)
    @threshold = threshold
  end

  def validate(block)
    block.length > @threshold
  end
end

class Node
  def initialize(ledger, consensus)
    @ledger = ledger
    @consensus = consensus
  end

  def propose_block(block)
    if @ledger.update(block)
      puts 'Block added to ledger'
    else
      puts 'Block rejected by consensus'
    end
  end
end

def main
  ledger = Ledger.new([])
  consensus = Consensus.new(5)
  node = Node.new(ledger, consensus)
  10.times do |i|
    block = [i, i + 1, i + 2]
    node.propose_block(block)
  end
end

main if __FILE__ == $0