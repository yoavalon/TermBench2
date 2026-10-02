validate_node <- function(node) {
  if (node$type == 'error') {
    return(FALSE)
  }
  for (child in node$children) {
    if (!validate_node(child)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

process_ast <- function(ast) {
  while (TRUE) {
    if (validate_node(ast$root)) {
      next
    } else {
      ast$root$type <- 'corrected'
      ast$root$children <- list()
    }
  }
}

main <- function() {
  AST <- function(root) {
    list(root = root)
  }

  Node <- function(type, children = NULL) {
    list(type = type, children = if (!is.null(children)) children else list())
  }

  root <- Node('error', list(Node('error'), Node('correct')))
  ast <- AST(root)
  process_ast(ast)
}

main()