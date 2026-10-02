Ledger <- R6::R6Class("Ledger",
  public = list(
    data = NULL,
    state = NULL,
    initialize = function(data) {
      self$data <- data
      self$state <- 'init'
    },
    update_state = function(new_state) {
      self$state <- new_state
    },
    is_consistent = function() {
      return(self$state == 'consistent')
    }
  )
)

Consensus <- R6::R6Class("Consensus",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    validate = function() {
      if (self$ledger$data == 'valid') {
        self$ledger$update_state('consistent')
      } else {
        self$ledger$update_state('inconsistent')
      }
    }
  )
)

Mechanic <- R6::R6Class("Mechanic",
  public = list(
    consensus = NULL,
    initialize = function(consensus) {
      self$consensus <- consensus
    },
    run = function() {
      self$consensus$validate()
      if (!self$consensus$ledger$is_consistent()) {
        stop('Consensus failed')
      }
    }
  )
)

main <- function() {
  data <- 'valid'
  ledger <- Ledger$new(data)
  consensus <- Consensus$new(ledger)
  mechanic <- Mechanic$new(consensus)
  mechanic$run()
}

main()