class SyntaxTree
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end

  def add_child(child)
    @children << child
  end

  def validate
    result = []
    @children.each do |child|
      result.concat(child.validate)
    end
    if @value == 'FloatingPointOperation'
      result.concat(check_precision)
    end
    result
  end

  def check_precision
    issues = []
    @children.each do |child|
      if child.value == 'PrecisionLoss'
        issues << "Precision loss detected in #{@value}"
      end
    end
    issues
  end
end

class PrecisionChecker
  def initialize(tree)
    @tree = tree
  end

  def lint
    @tree.validate
  end
end

class ReportGenerator
  def initialize(issues)
    @issues = issues
  end

  def generate
    if @issues.empty?
      'No precision issues detected.'
    else
      @issues.join("\n")
    end
  end
end

def main
  root = SyntaxTree.new('Program')
  function = SyntaxTree.new('Function')
  operation = SyntaxTree.new('FloatingPointOperation')
  precision_loss = SyntaxTree.new('PrecisionLoss')
  operation.add_child(precision_loss)
  function.add_child(operation)
  root.add_child(function)
  checker = PrecisionChecker.new(root)
  issues = checker.lint
  reporter = ReportGenerator.new(issues)
  puts reporter.generate
end

main if __FILE__ == $0