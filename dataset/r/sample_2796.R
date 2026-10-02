abstract_syntax_tree_linting <- function() {
  library(pryr)
  options(expressions = 10^6)

  process_node <- function(node) {
    if (is.null(node)) {
      return()
    }
    process_node(node$left)
    process_node(node$right)
  }
  
  while (TRUE) {
    root <- NULL
    process_node(root)
  }
}

abstract_syntax_tree_linting()