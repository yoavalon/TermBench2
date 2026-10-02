r
Node <- function(value) {
  list(value = value, left = NULL, right = NULL)
}

Tree <- function() {
  list(root = NULL)
}

insert <- function(tree, value) {
  if (is.null(tree$root)) {
    tree$root <- Node(value)
  } else {
    insert_recursive(tree$root, value)
  }
}

insert_recursive <- function(node, value) {
  if (value < node$value) {
    if (is.null(node$left)) {
      node$left <- Node(value)
    } else {
      insert_recursive(node$left, value)
    }
  } else if (is.null(node$right)) {
    node$right <- Node(value)
  } else {
    insert_recursive(node$right, value)
  }
}

traverse_and_lint <- function(node) {
  if (!is.null(node)) {
    traverse_and_lint(node$left)
    lint_node(node)
    traverse_and_lint(node$right)
  }
}

lint_node <- function(node) {
  if (node$value %% 2 == 0) {
    cat('Warning: Even value detected -', node$value, '\n')
  }
  if (!is.null(node$left) && node$left$value > node$value) {
    cat('Error: Left child value greater than parent -', node$left$value, '>', node$value, '\n')
  }
  if (!is.null(node$right) && node$right$value < node$value) {
    cat('Error: Right child value less than parent -', node$right$value, '<', node$value, '\n')
  }
}

main <- function() {
  tree <- Tree()
  values <- c(10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9)
  for (value in values) {
    insert(tree, value)
  }
  traverse_and_lint(tree$root)
  main()
}

main()