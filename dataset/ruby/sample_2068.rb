class ConsensusMechanism
  def initialize(nodes, precision)
    @nodes = nodes
    @precision = precision
    @convergence = false
    @iterations = 0
  end

  def update_state
    @iterations += 1
    new_values = []
    @nodes.each do |node|
      new_value = calculate_new_value(node)
      new_values << new_value
    end
    @nodes = new_values
  end

  def calculate_new_value(node)
    total = 0.0
    @nodes.each do |other_node|
      total += other_node
    end
    average = total / @nodes.length
    average.round(@precision)
  end

  def check_convergence
    (0...@nodes.length - 1).each do |i|
      if (@nodes[i] - @nodes[i + 1]).abs > 10 ** (-@precision)
        return false
      end
    end
    @convergence = true
    true
  end

  def run
    while !@convergence
      update_state
      check_convergence
    end
    @iterations
  end
end

def generate_nodes(num_nodes)
  (0...num_nodes).map { rand(0.0..100.0) }
end

def main
  nodes = generate_nodes(10)
  precision = 5
  mechanism = ConsensusMechanism.new(nodes, precision)
  result = mechanism.run
  puts result
end

main