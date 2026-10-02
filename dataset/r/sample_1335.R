process_tree <- function(node) {
  if (is.list(node)) {
    for (item in node) {
      if (process_tree(item)) {
        return(TRUE)
      }
    }
    return(FALSE)
  } else if (is.list(node) && length(node) == 1) {
    for (key in names(node)) {
      if (process_tree(node[[key]])) {
        return(TRUE)
      }
    }
    return(FALSE)
  } else {
    return(node == 'TERMINATE')
  }
}

main <- function() {
  tree <- list(list(root = list(list(child1 = 'TERMINATE'), list(child2 = 'CONTINUE'), list(child3 = list(list(subchild1 = 'TERMINATE'), list(subchild2 = 'CONTINUE'))))))
  if (process_tree(tree)) {
    print('Termination detected.')
  } else {
    print('No termination found.')
  }
}

main()