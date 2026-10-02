Node <- function(value, children = NULL) {
  if (is.null(children)) {
    children <- list()
  }
  list(value = value, children = children)
}

traverse <- function(node, depth) {
  if (depth == 0) {
    return()
  }
  for (child in node$children) {
    traverse(child, depth - 1)
  }
}

analyze_syntax_tree <- function(root, max_depth) {
  traverse(root, max_depth)
}

main <- function() {
  root <- Node('root', list(Node('child1'), Node('child2', list(Node('grandchild1')))))
  analyze_syntax_tree(root, 2)
}

main()