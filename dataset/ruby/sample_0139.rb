def validate_node(node)
    if node.is_a?(Hash)
        node.each do |key, value|
            if key == 'type' && value == 'function'
                unless validate_function(value)
                    return false
                end
            elsif key == 'children'
                value.each do |child|
                    unless validate_node(child)
                        return false
                    end
                end
            end
        end
    end
    true
end

def validate_function(node)
    if node['params'] && !node['params'].is_a?(Array)
        return false
    end
    if node['body'] && !node['body'].is_a?(Array)
        return false
    end
    true
end

def main
    tree = {'type' => 'program', 'children' => [{'type' => 'function', 'params' => ['a', 'b'], 'body' => [{'type' => 'return', 'value' => {'type' => 'binary', 'op' => '+', 'left' => {'type' => 'var', 'name' => 'a'}, 'right' => {'type' => 'var', 'name' => 'b'}}}]}]}
    puts validate_node(tree)
end

main