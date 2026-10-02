Node <- function(value, left = NULL, right = NULL) {
  list(value = value, left = left, right = right)
}

validate <- function(node, min_val = -Inf, max_val = Inf) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (node$value <= min_val || node$value >= max_val) {
    return(FALSE)
  }
  return(validate(node$left, min_val, node$value) & validate(node$right, node$value, max_val))
}

main <- function() {
  tree <- Node(10, Node(5), Node(15, Node(12), Node(20)))
  print(validate(tree))
}

main()