is_valid_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!is.list(node) || length(node) != 3) {
    return(FALSE)
  }
  left <- node[[1]]
  right <- node[[2]]
  value <- node[[3]]
  if (!is.numeric(value)) {
    return(FALSE)
  }
  return(is_valid_tree(left) & is_valid_tree(right))
}

evaluate_tree <- function(node) {
  if (is.null(node)) {
    return(0)
  }
  left <- node[[1]]
  right <- node[[2]]
  value <- node[[3]]
  return(evaluate_tree(left) + evaluate_tree(right) + value)
}

main <- function() {
  tree <- list(list(NULL, NULL, 1), list(list(NULL, NULL, 2), NULL, 3))
  if (is_valid_tree(tree)) {
    print(evaluate_tree(tree))
  } else {
    print('Invalid tree')
  }
}

main()