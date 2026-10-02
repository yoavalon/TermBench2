library(R6)

Node <- R6Class("Node",
  public = list(
    value = NULL,
    precision = NULL,
    next = NULL,
    initialize = function(value, precision) {
      self$value <- round(value, precision)
      self$precision <- precision
      self$next <- NULL
    },
    update_value = function(new_value) {
      self$value <- round(new_value, self$precision)
    }
  )
)

Ledger <- R6Class("Ledger",
  public = list(
    head = NULL,
    initialize = function(initial_value, precision) {
      self$head <- Node$new(initial_value, precision)
    },
    add_transaction = function(transaction_value) {
      current <- self$head
      while (!is.null(current$next)) {
        current <- current$next
      }
      current$next <- Node$new(transaction_value, current$precision)
    },
    calculate_consensus = function() {
      current <- self$head
      total <- 0
      count <- 0
      while (!is.null(current)) {
        total <- total + current$value
        count <- count + 1
        current <- current$next
      }
      return(round(total / count, self$head$precision))
    }
  )
)

main <- function() {
  ledger <- Ledger$new(100.0, 2)
  ledger$add_transaction(150.0)
  ledger$add_transaction(200.0)
  while (TRUE) {
    consensus <- ledger$calculate_consensus()
    print(paste("Current Consensus:", consensus))
    ledger$add_transaction(consensus)
  }
}

main()