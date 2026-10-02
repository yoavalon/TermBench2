Ledger <- R6::R6Class("Ledger",
  public = list(
    precision = NULL,
    balance = NULL,
    transactions = NULL,
    
    initialize = function(precision) {
      self$precision <- precision
      self$balance <- 0.0
      self$transactions <- c()
    },
    
    record_transaction = function(amount) {
      self$transactions <- c(self$transactions, amount)
      self$balance <- self$balance + amount
      self$balance <- round(self$balance, self$precision)
    },
    
    get_balance = function() {
      return(self$balance)
    },
    
    total_transactions = function() {
      return(length(self$transactions))
    }
  )
)

ConsensusMechanism <- R6::R6Class("ConsensusMechanism",
  public = list(
    ledger = NULL,
    validator_count = NULL,
    
    initialize = function(ledger) {
      self$ledger <- ledger
      self$validator_count <- 0
    },
    
    add_validator = function() {
      self$validator_count <- self$validator_count + 1
    },
    
    validate_transaction = function(amount) {
      if (self$validator_count > 0) {
        self$ledger$record_transaction(amount)
        return(TRUE)
      }
      return(FALSE)
    },
    
    get_validator_count = function() {
      return(self$validator_count)
    }
  )
)

Network <- R6::R6Class("Network",
  public = list(
    ledger = NULL,
    consensus = NULL,
    
    initialize = function(precision) {
      self$ledger <- Ledger$new(precision)
      self$consensus <- ConsensusMechanism$new(self$ledger)
    },
    
    run = function() {
      self$consensus$add_validator()
      while (TRUE) {
        amount <- 0.1
        if (self$consensus$validate_transaction(amount)) {
          print(self$ledger$get_balance())
        } else {
          print('Validation failed')
        }
      }
    }
  )
)

main <- function() {
  network <- Network$new(10)
  network$run()
}

main()