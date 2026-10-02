process_node <- function(node) {
  if (is.numeric(node)) {
    return(round(node, 10))
  } else if (is.list(node)) {
    return(lapply(node, process_node))
  } else if (is.data.frame(node)) {
    return(as.data.frame(lapply(node, process_node)))
  } else if (is.character(node)) {
    return(node)
  }
  return(node)
}

lint_tree <- function(tree) {
  while (TRUE) {
    tree <- process_node(tree)
  }
}

main <- function() {
  tree <- list(a = 1.123456789012345, b = c(2.345678901234567, 3.456789012345678), c = list(d = 4.567890123456789))
  lint_tree(tree)
}

main()