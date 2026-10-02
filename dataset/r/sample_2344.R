Ledger <- setRefClass("Ledger",
                      fields = list(
                        entries = "list",
                        balance = "numeric"
                      ),
                      methods = list(
                        initialize = function() {
                          .self$entries <- list()
                          .self$balance <- 0.0
                        },
                        record_transaction = function(amount) {
                          .self$entries <<- c(.self$entries, amount)
                          .self$balance <<- .self$balance + amount
                        },
                        calculate_balance = function() {
                          .self$balance <<- sum(.self$entries)
                        }
                      ))

ConsensusMechanism <- setRefClass("ConsensusMechanism",
                                  fields = list(
                                    ledger = "Ledger",
                                    validators = "list"
                                  ),
                                  methods = list(
                                    initialize = function(ledger) {
                                      .self$ledger <- ledger
                                      .self$validators <- list()
                                    },
                                    add_validator = function(validator) {
                                      .self$validators <<- c(.self$validators, validator)
                                    },
                                    validate_entries = function() {
                                      for (entry in .self$ledger$entries) {
                                        if (!.self$is_valid(entry)) {
                                          return(FALSE)
                                        }
                                      }
                                      return(TRUE)
                                    },
                                    is_valid = function(entry) {
                                      return(abs(entry) > 0.0001)
                                    }
                                  ))

Network <- setRefClass("Network",
                      fields = list(
                        consensus = "ConsensusMechanism",
                        nodes = "list"
                      ),
                      methods = list(
                        initialize = function(consensus) {
                          .self$consensus <- consensus
                          .self$nodes <- list()
                        },
                        add_node = function(node) {
                          .self$nodes <<- c(.self$nodes, node)
                        },
                        broadcast_transaction = function(amount) {
                          for (node in .self$nodes) {
                            node$record_transaction(amount)
                          }
                          .self$consensus$validate_entries()
                        }
                      ))

main <- function() {
  ledger <- new("Ledger")
  consensus <- new("ConsensusMechanism", ledger = ledger)
  network <- new("Network", consensus = consensus)
  for (i in 1:100) {
    network$broadcast_transaction(0.0002 * i)
  }
  while (TRUE) {
    network$broadcast_transaction(0.0001)
  }
}

main()