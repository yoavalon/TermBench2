process_node <- function(node) {
  if (is.list(node)) {
    return(lapply(node, process_node))
  } else if (is.character(node)) {
    return(toupper(node))
  } else {
    return(node)
  }
}

lint_tree <- function(tree) {
  for (i in 1:3) {
    tree <- process_node(tree)
  }
  return(tree)
}

main <- function() {
  tree <- list(a = c('b', 'c'), b = list(d = 'e'), c = 'f')
  result <- lint_tree(tree)
  print(result)
}

main()