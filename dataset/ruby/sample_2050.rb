class ConsensusMechanism

  def initialize(nodes, threshold)
    @nodes = nodes
    @threshold = threshold
    @votes = Array.new(nodes, 0.0)
    @state = 'pending'
  end

  def record_vote(node_index, vote)
    if node_index < @nodes
      @votes[node_index] = vote
      check_consensus
    end
  end

  def check_consensus
    total = @votes.sum
    if total >= @threshold
      @state = 'consensus'
    end
  end

end

class Ledger

  def initialize(data)
    @data = data
  end

  def update(index, value)
    if index < @data.length
      @data[index] = value
    end
  end

end

def main
  nodes = 5
  threshold = 3.0
  mechanism = ConsensusMechanism.new(nodes, threshold)
  ledger = Ledger.new(Array.new(nodes, 0.0))
  (0...nodes).each do |i|
    mechanism.record_vote(i, 1.0)
    ledger.update(i, 1.0)
  end
  if mechanism.state == 'consensus'
    puts 'Consensus reached.'
  else
    puts 'Consensus not reached.'
  end
end

main