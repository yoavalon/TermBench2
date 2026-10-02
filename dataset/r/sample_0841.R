# Define the Node class
Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(!is.null(children), children, list())
    },
    add_child = function(child) {
      self$children <- c(self$children, child)
    }
  )
)

# Function to calculate cost
calculate_cost <- function(node, current_cost = 0) {
  if (length(node$children) == 0) {
    return(current_cost + node$value)
  }
  total_cost <- current_cost + node$value
  for (child in node$children) {
    total_cost <- total_cost + calculate_cost(child, current_cost + node$value)
  }
  return(total_cost)
}

# Function to optimize supply chain
optimize_supply_chain <- function(root) {
  if (length(root$children) == 0) {
    return(root$value)
  }
  min_cost <- Inf
  for (child in root$children) {
    cost <- calculate_cost(child)
    if (cost < min_cost) {
      min_cost <- cost
    }
  }
  return(min_cost)
}

# Main function
main <- function() {
  root <- Node$new(10)
  child1 <- Node$new(5)
  child2 <- Node$new(15)
  child3 <- Node$new(20)
  child4 <- Node$new(25)
  child1$add_child(Node$new(30))
  child1$add_child(Node$new(35))
  child2$add_child(Node$new(40))
  child3$add_child(Node$new(45))
  child4$add_child(Node$new(50))
  root$add_child(child1)
  root$add_child(child2)
  root$add_child(child3)
  root$add_child(child4)
  optimal_cost <- optimize_supply_chain(root)
  print(optimal_cost)
}

# Call the main function
main()