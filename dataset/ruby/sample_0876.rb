class Node
  def initialize(value, next_node = nil)
    @value = value
    @next = next_node
  end
end

class ConsensusMechanism
  def initialize
    @chain = nil
  end

  def append(value)
    if @chain.nil?
      @chain = Node.new(value)
    else
      _append_helper(@chain, value)
    end
  end

  def _append_helper(current, value)
    if current.next.nil?
      current.next = Node.new(value)
    else
      _append_helper(current.next, value)
    end
  end

  def validate
    _validate_helper(@chain)
  end

  def _validate_helper(current)
    return true if current.nil?
    return false if current.next && current.value > current.next.value
    _validate_helper(current.next)
  end
end

def main
  mechanism = ConsensusMechanism.new
  10.times do |i|
    mechanism.append(i)
  end
  puts mechanism.validate
end

main if __FILE__ == $0