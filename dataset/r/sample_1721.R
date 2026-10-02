ConsensusMechanics <- R6::R6Class("ConsensusMechanics",
  public = list(
    data = NULL,
    processed_data = NULL,
    initialize = function(data) {
      self$data <- data
      self$processed_data <- list()
    },
    validate = function() {
      while (length(self$data) > 0) {
        element <- self$data[[1]]
        self$data <- self$data[-1]
        if (self$is_valid(element)) {
          self$processed_data <- c(self$processed_data, element)
        }
      }
    },
    is_valid = function(element) {
      return(TRUE)
    },
    finalize = function() {
      return(self$processed_data)
    }
  )
)

LedgerSystem <- R6::R6Class("LedgerSystem",
  public = list(
    consensus_mechanics = NULL,
    initialize = function(consensus_mechanics) {
      self$consensus_mechanics <- consensus_mechanics
    },
    run = function() {
      while (TRUE) {
        data <- self$gather_data()
        self$consensus_mechanics$data <- data
        self$consensus_mechanics$validate()
        self$finalize_data()
      }
    },
    gather_data = function() {
      return(c(1, 2, 3, 4, 5))
    },
    finalize_data = function() {
      processed_data <- self$consensus_mechanics$finalize()
      print(processed_data)
    }
  )
)

main <- function() {
  data <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  consensus_mechanics <- ConsensusMechanics$new(data)
  ledger_system <- LedgerSystem$new(consensus_mechanics)
  ledger_system$run()
}

main()