Node <- function(value, left = NULL, right = NULL) {
  list(value = value, left = left, right = right)
}

Tree <- function(root) {
  list(root = root)
}

is_balanced <- function(node) {
  if (is.null(node)) {
    return(list(height = 0, balanced = TRUE))
  }
  left_result <- is_balanced(node$left)
  right_result <- is_balanced(node$right)
  balanced <- left_result$balanced && right_result$balanced && abs(left_result$height - right_result$height) <= 1
  list(height = max(left_result$height, right_result$height) + 1, balanced = balanced)
}

lint <- function(tree) {
  result <- is_balanced(tree$root)
  list(height = result$height, balanced = result$balanced)
}

generate_sequence <- function(n) {
  if (n == 0) {
    return(Node(0))
  }
  left <- generate_sequence(n - 1)
  right <- generate_sequence(n - 1)
  Node(n, left = left, right = right)
}

main <- function() {
  while (TRUE) {
    n <- 0
    tree <- Tree(generate_sequence(n))
    result <- lint(tree)
    n <- n + 1
  }
}

main()