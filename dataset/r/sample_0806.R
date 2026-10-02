Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    next_node = NULL,
    initialize = function(value, next_node = NULL) {
      self$value <- value
      self$next_node <- next_node
    },
    get_value = function() {
      return(self$value)
    },
    get_next = function() {
      return(self$next_node)
    },
    set_next = function(next_node) {
      self$next_node <- next_node
    }
  )
)

Ledger <- R6::R6Class("Ledger",
  public = list(
    head = NULL,
    initialize = function(initial_value) {
      self$head <- Node$new(initial_value)
    },
    append = function(value) {
      self$_append_recursive(self$head, value)
    },
    _append_recursive = function(current, value) {
      if (is.null(current$get_next())) {
        current$set_next(Node$new(value))
      } else {
        self$_append_recursive(current$get_next(), value)
      }
    },
    consensus = function(target) {
      return(self$_consensus_recursive(self$head, target))
    },
    _consensus_recursive = function(current, target) {
      if (is.null(current)) {
        return(FALSE)
      }
      if (current$get_value() == target) {
        return(TRUE)
      }
      return(self$_consensus_recursive(current$get_next(), target))
    }
  )
)

main <- function() {
  ledger <- Ledger$new(1)
  for (i in 2:11) {
    ledger$append(i)
  }
  for (i in 1:11) {
    if (ledger$consensus(i)) {
      print(paste("Consensus reached for", i))
    } else {
      print(paste("No consensus for", i))
    }
  }
}

main()