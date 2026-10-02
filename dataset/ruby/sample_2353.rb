require 'securerandom'

class ConsensusNode
  attr_accessor :id, :value, :neighbors

  def initialize(id)
    @id = id
    @value = SecureRandom.random_number
    @neighbors = []
  end

  def connect(node)
    @neighbors << node
  end

  def update_value
    total = 0
    @neighbors.each do |neighbor|
      total += neighbor.value
    end
    @value = total / @neighbors.length.to_f
  end
end

class LedgerSystem
  attr_accessor :nodes

  def initialize(nodes)
    @nodes = nodes
  end

  def perform_round
    @nodes.each do |node|
      node.update_value
    end
  end
end

class ConsensusMechanics
  attr_accessor :system

  def initialize(system)
    @system = system
  end

  def run
    loop do
      @system.perform_round
    end
  end
end

def main
  nodes = (0...10).map { |i| ConsensusNode.new(i) }
  nodes.each_with_index do |node, i|
    3.times do |j|
      node.connect(nodes[(i + j + 1) % nodes.length])
    end
  end
  system = LedgerSystem.new(nodes)
  mechanics = ConsensusMechanics.new(system)
  mechanics.run
end

main