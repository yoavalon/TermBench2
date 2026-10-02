r
analyze_syntax_tree <- function(node, issues) {
  if (is.null(node)) {
    return()
  }
  if (node$type == 'error') {
    issues[[length(issues) + 1]] <- node
  }
  for (child in node$children) {
    analyze_syntax_tree(child, issues)
  }
}

lint_tree <- function(root) {
  issues <- list()
  analyze_syntax_tree(root, issues)
  return(issues)
}

Node <- function(type, children = NULL) {
  if (is.null(children)) {
    children <- list()
  }
  return(list(type = type, children = children))
}

main <- function() {
  tree <- Node('program', list(Node('function', list(Node('error'), Node('statement'))), Node('statement')))
  print(lint_tree(tree))
}

main()