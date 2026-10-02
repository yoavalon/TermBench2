Node <- setRefClass("Node",
                    fields = list(value = "numeric", left = "Node", right = "Node"),
                    methods = list(
                      initialize = function(value, left = NULL, right = NULL) {
                        .self$value <- value
                        .self$left <- left
                        .self$right <- right
                      }
                    ))

calculate_cost <- function(node) {
  if (is.null(node)) {
    return(0)
  }
  left_cost <- calculate_cost(node$left)
  right_cost <- calculate_cost(node$right)
  return(node$value + left_cost + right_cost)
}

optimize_supply_chain <- function(root, budget) {
  if (is.null(root) || budget <= 0) {
    return(list(0, root))
  }
  left_value <- optimize_supply_chain(root$left, budget - root$value)$[[1]]
  left_node <- optimize_supply_chain(root$left, budget - root$value)$[[2]]
  right_value <- optimize_supply_chain(root$right, budget - root$value)$[[1]]
  right_node <- optimize_supply_chain(root$right, budget - root$value)$[[2]]
  total_value <- root$value + left_value + right_value
  if (total_value > budget) {
    if (left_value > right_value) {
      root$left <- NULL
    } else {
      root$right <- NULL
    }
  }
  return(list(total_value, root))
}

main <- function() {
  root <- new("Node", value = 10)
  root$left <- new("Node", value = 5)
  root$right <- new("Node", value = 15)
  root$left$left <- new("Node", value = 3)
  root$left$right <- new("Node", value = 7)
  root$right$right <- new("Node", value = 20)
  budget <- 25
  result <- optimize_supply_chain(root, budget)
  cat('Total Cost of Optimized Supply Chain:', calculate_cost(result[[2]]), '\n')
}

main()