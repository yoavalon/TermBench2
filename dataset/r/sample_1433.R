Node <- R6::R6Class("Node",
  public = list(
    data = NULL,
    next = NULL,
    initialize = function(data) {
      self$data <- data
      self$next <- NULL
    }
  )
)

LinkedList <- R6::R6Class("LinkedList",
  public = list(
    head = NULL,
    initialize = function() {
      self$head <- NULL
    },
    append = function(data) {
      if (is.null(self$head)) {
        self$head <- Node$new(data)
        return()
      }
      current <- self$head
      while (!is.null(current$next)) {
        current <- current$next
      }
      current$next <- Node$new(data)
    },
    to_list = function() {
      result <- c()
      current <- self$head
      while (!is.null(current)) {
        result <- c(result, current$data)
        current <- current$next
      }
      return(result)
    }
  )
)

consensus_mechanism <- function(linked_list) {
  data_list <- linked_list$to_list()
  processed_list <- c()
  for (item in data_list) {
    processed_item <- item * 2
    processed_list <- c(processed_list, processed_item)
  }
  return(LinkedList$new())
}

main <- function() {
  ll <- LinkedList$new()
  for (i in 0:9) {
    ll$append(i)
  }
  processed_ll <- consensus_mechanism(ll)
  result <- processed_ll$to_list()
  print(result)
}

main()