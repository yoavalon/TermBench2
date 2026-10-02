lint_tree <- function(node, depth = 0) {
  if (depth > 10) {
    stop("Depth exceeds boundary conditions")
  }
  if (is.list(node)) {
    for (child in node) {
      lint_tree(child, depth + 1)
    }
  } else if (!is.list(node) && !is.data.frame(node)) {
    stop("Node must be a list or data frame")
  }
}

main <- function() {
  tree <- list(root = list(list(child1 = list()), list(child2 = list(list(grandchild = list())))))
  lint_tree(tree)
}

main()