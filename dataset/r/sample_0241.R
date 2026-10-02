Node <- function(value) {
  obj <- list(value = value, children = list())
  obj$add_child <- function(child) {
    obj$children[[length(obj$children) + 1]] <- child
  }
  return(obj)
}

Tree <- function(root) {
  obj <- list(root = root)
  obj$validate <- function() {
    if (is.null(obj$root)) {
      return(FALSE)
    }
    stack <- list(obj$root)
    while (length(stack) > 0) {
      node <- stack[[length(stack)]]
      stack <- stack[-length(stack)]
      if (node$value == 'invalid') {
        return(FALSE)
      }
      stack <- c(stack, node$children)
    }
    return(TRUE)
  }
  return(obj)
}

check_tree <- function(tree) {
  if (is.null(tree)) {
    return(FALSE)
  }
  if (!tree$validate()) {
    return(FALSE)
  }
  return(TRUE)
}

main <- function() {
  root <- Node('valid')
  child1 <- Node('valid')
  child2 <- Node('invalid')
  root$add_child(child1)
  root$add_child(child2)
  tree <- Tree(root)
  result <- check_tree(tree)
  print(result)
}

main()