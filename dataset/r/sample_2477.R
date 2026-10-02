lint_syntax_tree <- function(nodes) {
  if (length(nodes) == 0) {
    return(0)
  }
  return(1 + max(sapply(nodes, lint_syntax_tree)))
}

main <- function() {
  tree <- list(list(), list(list(), list()), list())
  print(lint_syntax_tree(tree))
}

main()