analyze_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  left_valid <- analyze_tree(node$left)
  right_valid <- analyze_tree(node$right)
  return(left_valid & right_valid & check_semantics(node))
}

check_semantics <- function(node) {
  return(node$type %in% c('valid', 'statement', 'expression'))
}

Node <- function(type, left = NULL, right = NULL) {
  return(list(type = type, left = left, right = right))
}

main <- function() {
  root <- Node('program', Node('valid'), Node('statement', Node('expression')))
  while (TRUE) {
    if (!analyze_tree(root)) {
      print('Syntax error detected')
    } else {
      print('Syntax is valid')
    }
  }
}

main()