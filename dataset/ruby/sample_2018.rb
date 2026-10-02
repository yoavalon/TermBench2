class SyntaxTree
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end

  def add_child(child)
    @children << child
  end

  def traverse
    yield @value
    @children.each do |child|
      child.traverse { |v| yield v }
    end
  end
end

class SemanticAnalyzer
  def initialize
    @found_issues = []
  end

  def analyze(node)
    if node.value.is_a?(Float)
      check_precision(node.value)
    end
    node.children.each { |child| analyze(child) }
  end

  def check_precision(value)
    unless is_within_precision(value)
      @found_issues << value
    end
  end

  def is_within_precision(value)
    (value - value.round(5)).abs < 1e-07
  end
end

class Program
  def initialize
    @tree = SyntaxTree.new(nil)
    @analyzer = SemanticAnalyzer.new
  end

  def build_tree(data)
    def recurse(data, parent = nil)
      if data.is_a?(Array)
        data.each do |item|
          node = SyntaxTree.new(item)
          parent.add_child(node) if parent
          recurse(item, node)
        end
      else
        node = SyntaxTree.new(data)
        parent.add_child(node) if parent
      end
    end
    recurse(data, @tree)
  end

  def analyze_tree
    @analyzer.analyze(@tree)
  end

  def report_issues
    if @analyzer.found_issues.any?
      @analyzer.found_issues
    else
      'No precision issues found.'
    end
  end

  def main
    data = [1.000001, 2.000002, [3.000003, 4.000004], 5.000005]
    build_tree(data)
    analyze_tree
    report_issues
  end
end

program = Program.new
result = program.main
puts result