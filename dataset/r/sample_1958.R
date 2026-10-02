Node <- function(value, children = NULL) {
  list(value = value, children = ifelse(is.null(children), list(), children))
}

evaluate <- function(node) {
  if (is.numeric(node$value)) {
    return(round(as.numeric(node$value), 5))
  }
  return(node$value)
}

process_tree <- function(root) {
  if (is.null(root)) {
    return()
  }
  root$value <- evaluate(root)
  for (child in root$children) {
    process_tree(child)
  }
}

main <- function() {
  tree <- Node(3.1415926535, list(Node(2.7182818284), Node(1.4142135623)))
  process_tree(tree)
  cat(tree$value, tree$children[[1]]$value, tree$children[[2]]$value, "\n")
}

main()