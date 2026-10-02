r
Node <- setRefClass("Node", fields = list(value = "numeric", left = "Node", right = "Node"),
                    methods = list(
                      initialize = function(value) {
                        .self$value <- value
                        .self$left <- NULL
                        .self$right <- NULL
                      }
                    ))

Ledger <- setRefClass("Ledger", fields = list(root = "Node"),
                    methods = list(
                      initialize = function() {
                        .self$root <- NULL
                      },
                      insert = function(value) {
                        if (is.null(.self$root)) {
                          .self$root <- new("Node", value = value)
                        } else {
                          .self$_insert(.self$root, value)
                        }
                      },
                      _insert = function(node, value) {
                        if (value < node$value) {
                          if (!is.null(node$left)) {
                            .self$_insert(node$left, value)
                          } else {
                            node$left <<- new("Node", value = value)
                          }
                        } else {
                          if (!is.null(node$right)) {
                            .self$_insert(node$right, value)
                          } else {
                            node$right <<- new("Node", value = value)
                          }
                        }
                      }
                    ))

Consensus <- setRefClass("Consensus", fields = list(ledger = "Ledger"),
                      methods = list(
                        initialize = function(ledger) {
                          .self$ledger <- ledger
                        },
                        validate = function() {
                          .self$_validate(.self$ledger$root)
                        },
                        _validate = function(node) {
                          if (is.null(node)) {
                            return(TRUE)
                          }
                          if (!is.null(node$left) && node$left$value > node$value) {
                            return(FALSE)
                          }
                          if (!is.null(node$right) && node$right$value < node$value) {
                            return(FALSE)
                          }
                          return(.self$_validate(node$left) & .self$_validate(node$right))
                        }
                      ))

main <- function() {
  ledger <- new("Ledger")
  for (i in 0:99) {
    ledger$insert(i)
  }
  consensus <- new("Consensus", ledger = ledger)
  print(consensus$validate())
}

main()