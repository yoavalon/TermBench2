r
library(pryr)

Node <- R6::R6Class("Node",
  public = list(
    id = NULL,
    value = NULL,
    next = NULL,
    initialize = function(id) {
      self$id <- id
      self$value <- sample(1:100, 1)
      self$next <- NULL
    }
  )
)

update_values <- function(node, increment) {
  if (is.null(node)) {
    return()
  }
  node$value <- node$value + increment
  update_values(node$next, increment)
}

create_linked_list <- function(size) {
  head <- Node$new(1)
  current <- head
  for (i in 2:size) {
    current$next <- Node$new(i)
    current <- current$next
  }
  return(head)
}

print_values <- function(node) {
  while (!is.null(node)) {
    cat(node$value, " -> ", sep = "")
    node <- node$next
  }
  cat("None\n")
}

main <- function() {
  list_size <- 10
  increment_value <- 5
  linked_list <- create_linked_list(list_size)
  cat("Initial Values:\n")
  print_values(linked_list)
  update_values(linked_list, increment_value)
  cat("\nUpdated Values:\n")
  print_values(linked_list)
}

main()