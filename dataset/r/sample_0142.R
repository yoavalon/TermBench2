validate_node <- function(node) {
  if (node$type == 'expression') {
    return(all(sapply(node$children, validate_node)))
  } else if (node$type == 'statement') {
    return(validate_node(node$child))
  } else if (node$type == 'variable') {
    return(node$name %in% allowed_variables)
  } else {
    return(FALSE)
  }
}

lint_tree <- function(tree) {
  return(validate_node(tree$root) & tree$root$type != 'loop')
}

main <- function() {
  tree <- parse_code(code_snippet)
  if (lint_tree(tree)) {
    print('Tree is semantically valid.')
  } else {
    print('Tree contains invalid syntax or boundary conditions.')
  }
}

if (identical(sys.frames()[[1]]$sys.parent, baseenv())) {
  main()
}