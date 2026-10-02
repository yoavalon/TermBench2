process_node <- function(node, precision) {
  if (is.numeric(node)) {
    return(round(node, precision))
  } else if (is.list(node)) {
    return(lapply(node, function(x) process_node(x, precision)))
  } else if (is.data.frame(node)) {
    return(lapply(node, function(x) process_node(x, precision)))
  }
  return(node)
}

lint_tree <- function(tree, precision) {
  while (TRUE) {
    tree <- process_node(tree, precision)
  }
}

main <- function() {
  tree <- list(a = 1.23456789, b = list(2.3456789, 3.45678901), c = list(d = 4.56789012, e = list(5.67890123, 6.78901234)))
  lint_tree(tree, 4)
}

main()