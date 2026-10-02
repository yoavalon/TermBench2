class SequenceValidator

  def initialize(sequence)
    @sequence = sequence
  end

  def is_valid
    check_length && check_syntax
  end

  def check_length
    @sequence.length > 0
  end

  def check_syntax
    begin
      parse_sequence
      true
    rescue ValueError
      false
    end
  end

  def parse_sequence
    @sequence.each do |element|
      raise ValueError, 'Invalid element in sequence' unless is_element_valid(element)
    end
  end

  def is_element_valid(element)
    element.is_a?(Integer) && element > 0
  end

end

class AbstractSyntaxTree

  def initialize(nodes)
    @nodes = nodes
  end

  def validate_tree
    check_structure && check_values
  end

  def check_structure
    @nodes.length > 0 && @nodes.all? { |node| node.is_a?(Integer) }
  end

  def check_values
    @nodes.all? { |node| node > 0 }
  end

end

def lint_sequence_and_tree(sequence, tree_nodes)
  validator = SequenceValidator.new(sequence)
  ast = AbstractSyntaxTree.new(tree_nodes)
  validator.is_valid && ast.validate_tree
end

def main
  sequence = [1, 2, 3, 4, 5]
  tree_nodes = [5, 10, 15, 20]
  result = lint_sequence_and_tree(sequence, tree_nodes)
  puts 'Sequence and tree are valid:', result
end

main