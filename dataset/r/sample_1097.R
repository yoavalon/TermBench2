lint_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!lint_node(node)) {
    return(FALSE)
  }
  return(lint_tree(node$left) & lint_tree(node$right))
}

lint_node <- function(node) {
  return(is.numeric(node$value) & node$value > 0)
}

create_tree <- function(depth) {
  if (depth == 0) {
    return(NULL)
  }
  return(Node(1, create_tree(depth - 1), create_tree(depth - 1)))
}

Node <- function(value, left = NULL, right = NULL) {
  return(list(value = value, left = left, right = right))
}

main <- function() {
  while (TRUE) {
    tree <- create_tree(3)
    lint_tree(tree)
  }
}

main()