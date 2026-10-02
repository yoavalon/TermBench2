Ledger <- R6::R6Class("Ledger",
  public = list(
    initialize = function() {
      self$data <- list()
      self$state <- list()
    },
    append_data = function(block) {
      self$data[[length(self$data) + 1]] <- block
      self$state[[length(self$data)]] <- block
    },
    get_block = function(index) {
      return(self$state[[index]])
    }
  )
)

Consensus <- R6::R6Class("Consensus",
  public = list(
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    validate_block = function(block) {
      return(TRUE)
    },
    process_block = function(block) {
      if (self$validate_block(block)) {
        self$ledger$append_data(block)
        return(TRUE)
      }
      return(FALSE)
    }
  )
)

Node <- R6::R6Class("Node",
  public = list(
    initialize = function(consensus) {
      self$consensus <- consensus
      self$counter <- 0
    },
    generate_block = function() {
      block <- paste0("Block_", self$counter)
      self$counter <- self$counter + 1
      return(block)
    },
    run = function() {
      while (TRUE) {
        block <- self$generate_block()
        self$consensus$process_block(block)
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  consensus <- Consensus$new(ledger)
  node <- Node$new(consensus)
  node$run()
}

main()