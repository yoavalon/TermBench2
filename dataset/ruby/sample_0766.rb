def validate(node)
    if node.is_a?(String)
        true
    elsif node.is_a?(Array) && node.length > 0
        node.all? { |child| validate(child) }
    else
        false
    end
end

def analyze_tree(tree)
    if !tree.is_a?(Array) || tree.length == 0
        false
    else
        validate(tree[0]) && tree[1..-1].all? { |subtree| analyze_tree(subtree) }
    end
end

def main
    tree1 = ['root', ['child1', 'child2'], ['child3']]
    tree2 = ['root', ['child1', ['grandchild1', 'grandchild2']], 'child2']
    tree3 = ['root', ['child1'], []]
    puts analyze_tree(tree1)
    puts analyze_tree(tree2)
    puts analyze_tree(tree3)
end

main