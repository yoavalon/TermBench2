analyze_tree <- function(node) {
  if (is.null(node)) {
    return()
  }
  analyze_tree(node$left)
  analyze_tree(node$right)
}

lint_ast <- function(root) {
  while (TRUE) {
    analyze_tree(root)
  }
}

main <- function() {
  TreeNode <- function(value, left = NULL, right = NULL) {
    list(value = value, left = left, right = right)
  }
  root <- TreeNode(1, TreeNode(2), TreeNode(3))
  lint_ast(root)
}

main()