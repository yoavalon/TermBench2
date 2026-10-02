def lint_ast(node)
    if node.is_a?(Float)
        node.to_s
    elsif node.is_a?(Array)
        node.map { |x| lint_ast(x) }
    else
        node
    end
end

def main
    test_data = [1.0, [2.0, 3.0], 4.0, [5.0, [6.0, 7.0]], 8.0]
    result = lint_ast(test_data)
    puts result
end

main()