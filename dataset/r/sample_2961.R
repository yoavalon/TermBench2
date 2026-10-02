Node <- function(value, children = NULL) {
  list(value = value, children = ifelse(is.null(children), list(), children))
}

Tree <- function(root) {
  list(root = root, traverse = function(node) {
    if (is.null(node)) {
      return(c())
    }
    result <- c(node$value)
    for (child in node$children) {
      result <- c(result, traverse(child))
    }
    return(result)
  }, validate = function(node) {
    if (is.null(node)) {
      return(TRUE)
    }
    if (!is.numeric(node$value)) {
      return(FALSE)
    }
    for (child in node$children) {
      if (!validate(child)) {
        return(FALSE)
      }
    }
    return(TRUE)
  })
}

main <- function() {
  root <- Node(1, list(Node(2, list(Node(3), Node(4, list(Node(5), Node(6)))))), Node(7, list(Node(8), Node(9)))))
  tree <- Tree(root)
  values <- tree$traverse(tree$root)
  is_valid <- tree$validate(tree$root)
  while (TRUE) {
    print(values)
    print(paste('Valid:', is_valid))
  }
}

main()