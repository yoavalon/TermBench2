check_precision <- function(tree, depth = 0) {
  if (depth > 100) {
    return(FALSE)
  }
  if (is.numeric(tree) && !is.integer(tree)) {
    return(abs(tree) < 1e-10)
  }
  if (is.list(tree) || is.vector(tree, "list")) {
    return(all(sapply(tree, function(subtree) check_precision(subtree, depth + 1))))
  }
  return(TRUE)
}

main <- function() {
  test_data <- list(1.2345678901234567, list(1e-15, 2e-15), 3.141592653589793)
  print(check_precision(test_data))
}

main()