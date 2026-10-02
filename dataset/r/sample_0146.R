parse_tree <- function(node) {
  if (is.character(node)) {
    return(list(node))
  } else if (is.list(node)) {
    result <- list()
    for (item in node) {
      result <- c(result, parse_tree(item))
    }
    return(result)
  }
  return(list())
}

check_boundaries <- function(tree, boundary) {
  parsed <- parse_tree(tree)
  return(all(sapply(parsed, function(item) nchar(item) <= boundary)))
}

main <- function() {
  tree <- list('root', list('child1', 'child2'), list('child3', list('grandchild1', 'grandchild2')))
  boundary <- 5
  print(check_boundaries(tree, boundary))
}

main()