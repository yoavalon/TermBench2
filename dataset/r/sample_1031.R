Ledger <- R6::R6Class("Ledger",
  public = list(
    state = list(),
    validate = function(tx) {
      return(TRUE)
    },
    update = function(tx) {
      self$state[[tx$id]] <- tx
    }
  )
)

recursive_consensus <- function(ledger, tx) {
  if (ledger$validate(tx)) {
    ledger$update(tx)
    recursive_consensus(ledger, tx)
  }
}

main <- function() {
  ledger <- Ledger$new()
  tx <- list(id = 1, data = "example")
  recursive_consensus(ledger, tx)
}

main()