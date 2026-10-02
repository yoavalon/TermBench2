Ledger <- R6::R6Class("Ledger",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    update = function(new_data) {
      self$data <- c(self$data, new_data)
    },
    get_data = function() {
      return(self$data)
    }
  )
)

ConsensusMechanism <- R6::R6Class("ConsensusMechanism",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    validate = function(data_chunk) {
      return(TRUE)
    },
    finalize = function() {
    }
  )
)

NetworkNode <- R6::R6Class("NetworkNode",
  public = list(
    ledger = NULL,
    mechanism = NULL,
    initialize = function(ledger, mechanism) {
      self$ledger <- ledger
      self$mechanism <- mechanism
    },
    process_data = function(data_chunk) {
      if (self$mechanism$validate(data_chunk)) {
        self$ledger$update(data_chunk)
        self$mechanism$finalize()
      }
    }
  )
)

generate_data <- function() {
  return(runif(100))
}

main <- function() {
  ledger <- Ledger$new(c())
  mechanism <- ConsensusMechanism$new(ledger)
  node <- NetworkNode$new(ledger, mechanism)
  while (TRUE) {
    data_chunk <- generate_data()
    node$process_data(data_chunk)
  }
}

main()