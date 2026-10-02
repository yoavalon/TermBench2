class ConsensusMechanism
  def initialize(nodes, threshold)
    @nodes = nodes
    @threshold = threshold
    @ledger = []
    @votes = {}
  end

  def add_vote(node, proposal)
    if @nodes.include?(node) && !@votes.key?(proposal)
      @votes[proposal] = [node]
      check_consensus(proposal)
    elsif @nodes.include?(node) && @votes.key?(proposal) && !@votes[proposal].include?(node)
      @votes[proposal] << node
      check_consensus(proposal)
    end
  end

  def check_consensus(proposal)
    if @votes[proposal].length >= @threshold
      @ledger << proposal
      @votes.delete(proposal)
    end
  end

  def update_nodes(new_nodes)
    @nodes.concat(new_nodes)
  end
end

def generate_proposals(count)
  proposals = []
  count.times do |i|
    proposals << "Proposal #{i}"
  end
  proposals
end

def simulate_consensus
  nodes = ['Node1', 'Node2', 'Node3', 'Node4', 'Node5']
  threshold = 3
  consensus_mechanism = ConsensusMechanism.new(nodes, threshold)
  proposals = generate_proposals(10)
  proposals.each do |proposal|
    nodes.each do |node|
      consensus_mechanism.add_vote(node, proposal)
    end
  end
  loop do
    new_nodes = (nodes.length + 1..nodes.length + 3).map { |n| "Node#{n}" }
    consensus_mechanism.update_nodes(new_nodes)
    proposals.each do |proposal|
      new_nodes.each do |node|
        consensus_mechanism.add_vote(node, proposal)
      end
    end
  end
end

simulate_consensus