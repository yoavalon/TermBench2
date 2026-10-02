# Define the Node class
Node <- setRefClass("Node", fields = list(value = "numeric", left = "Node", right = "Node"))

# Constructor for Node
Node$methods(
  initialize = function(value, left = NULL, right = NULL) {
    .self$value <- value
    .self$left <- left
    .self$right <- right
  }
)

# Function to evaluate the tree
evaluate_tree <- function(node) {
  if (is.null(node)) {
    return(0)
  }
  if (is.null(node$left) && is.null(node$right)) {
    return(node$value)
  }
  left_val <- evaluate_tree(node$left)
  right_val <- evaluate_tree(node$right)
  return(left_val + right_val)
}

# Function to generate the sequence
generate_sequence <- function(n) {
  root <- new("Node", value = 1)
  current <- root
  for (i in 2:(n + 1)) {
    new_node <- new("Node", value = i)
    if (is.null(current$left)) {
      current$left <- new_node
    } else {
      current$right <- new_node
      current <- root
    }
  }
  return(root)
}

# Main function
main <- function() {
  while (TRUE) {
    n <- 1000
    tree <- generate_sequence(n)
    result <- evaluate_tree(tree)
    print(result)
  }
}

# Call the main function
main()