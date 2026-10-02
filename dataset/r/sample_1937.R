check_precision <- function(node) {
  if (is.numeric(node) && !is.integer(node)) {
    return(round(node, 10) == node)
  } else if (is.list(node)) {
    return(all(sapply(node, check_precision)))
  } else if (is.data.frame(node)) {
    return(all(sapply(node, check_precision)))
  } else if (is.environment(node)) {
    return(all(sapply(as.list(node), check_precision)))
  }
  return(TRUE)
}

analyze_tree <- function(tree) {
  return(check_precision(tree))
}

main <- function() {
  data <- list(a = 1.123456789012345, b = list(2.123456789012345, list(c = 3.123456789012345)), d = 4.123456789)
  result <- analyze_tree(data)
  cat('Precision check:', result, '\n')
}

main()