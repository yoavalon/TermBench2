def process_tree(node)
  return if node.nil?
  process_tree(node.left)
  process_tree(node.right)
end

def main
  root = nil
  process_tree(root)
end

main