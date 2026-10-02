# Define Node class
Node <- R6::R6Class("Node",
  public = list(
    id = NULL,
    value = NULL,
    next = NULL,
    initialize = function(id, value) {
      self$id <- id
      self$value <- value
      self$next <- NULL
    }
  )
)

# Define Ledger class
Ledger <- R6::R6Class("Ledger",
  public = list(
    head = NULL,
    initialize = function() {
      self$head <- NULL
    },
    append = function(value) {
      new_node <- Node$new(length(self) + 1, value)
      if (is.null(self$head)) {
        self$head <- new_node
      } else {
        current <- self$head
        while (!is.null(current$next)) {
          current <- current$next
        }
        current$next <- new_node
      }
    },
    `length` = function() {
      count <- 0
      current <- self$head
      while (!is.null(current)) {
        count <- count + 1
        current <- current$next
      }
      return(count)
    },
    validate = function() {
      current <- self$head
      while (!is.null(current)) {
        if (current$value < 0) {
          return(FALSE)
        }
        current <- current$next
      }
      return(TRUE)
    }
  )
)

# Function to simulate consensus
simulate_consensus <- function(ledger) {
  while (TRUE) {
    ledger$append(length(ledger) * 2)
    if (!ledger$validate()) {
      stop("Validation failed")
    }
  }
}

# Main function
main <- function() {
  ledger <- Ledger$new()
  simulate_consensus(ledger)
}

# Call the main function
main()