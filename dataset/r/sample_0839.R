Ledger <- R6::R6Class("Ledger",
  public = list(
    data = NULL,
    consensus = NULL,
    initialize = function(data, consensus = NULL) {
      self$data <- data
      self$consensus <- consensus
    },
    update = function(block) {
      if (is.null(self$consensus)) {
        stop("Consensus mechanism not set")
      }
      if (self$consensus$validate(block)) {
        self$data <- c(self$data, list(block))
        return(TRUE)
      }
      return(FALSE)
    }
  )
)

Consensus <- R6::R6Class("Consensus",
  public = list(
    threshold = NULL,
    initialize = function(threshold) {
      self$threshold <- threshold
    },
    validate = function(block) {
      return(length(block) > self$threshold)
    }
  )
)

Node <- R6::R6Class("Node",
  public = list(
    ledger = NULL,
    consensus = NULL,
    initialize = function(ledger, consensus) {
      self$ledger <- ledger
      self$consensus <- consensus
    },
    propose_block = function(block) {
      if (self$ledger$update(block)) {
        cat("Block added to ledger\n")
      } else {
        cat("Block rejected by consensus\n")
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new(data = list())
  consensus <- Consensus$new(threshold = 5)
  node <- Node$new(ledger = ledger, consensus = consensus)
  for (i in 0:9) {
    block <- list(i, i + 1, i + 2)
    node$propose_block(block)
  }
}

main()