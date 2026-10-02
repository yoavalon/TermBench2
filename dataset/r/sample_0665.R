lint_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!is.list(node) || length(node) < 2) {
    return(FALSE)
  }
  if (!is.character(node[1])) {
    return(FALSE)
  }
  return(all(sapply(node[2:length(node)], lint_tree)))
}

main <- function() {
  tree <- list('program', list('statement', list('expression', 'var', 'value')))
  print(lint_tree(tree))
}

main()