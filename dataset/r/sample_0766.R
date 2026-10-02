validate <- function(node) {
  if (is.character(node)) {
    return(TRUE)
  } else if (is.list(node) && length(node) > 0) {
    return(all(sapply(node, validate)))
  } else {
    return(FALSE)
  }
}

analyze_tree <- function(tree) {
  if (!is.list(tree) || length(tree) == 0) {
    return(FALSE)
  }
  return(validate(tree[[1]]) && all(sapply(tree[-1], analyze_tree)))
}

main <- function() {
  tree1 <- list('root', list('child1', 'child2'), list('child3'))
  tree2 <- list('root', list('child1', list('grandchild1', 'grandchild2')), 'child2')
  tree3 <- list('root', list('child1'), list())
  print(analyze_tree(tree1))
  print(analyze_tree(tree2))
  print(analyze_tree(tree3))
}

main()