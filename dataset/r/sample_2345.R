r
LedgerNode <- setRefClass("LedgerNode",
    fields = list(value = "numeric", next = "LedgerNode"),
    methods = list(
        set_next = function(node) {
            .self$next <- node
        }
    )
)

LedgerChain <- setRefClass("LedgerChain",
    fields = list(head = "LedgerNode"),
    methods = list(
        append = function(value) {
            new_node <- LedgerNode$new(value = value)
            if (is.null(.self$head)) {
                .self$head <- new_node
            } else {
                current <- .self$head
                while (!is.null(current$next)) {
                    current <- current$next
                }
                current$set_next(new_node)
            }
        },
        calculate_consensus = function() {
            current <- .self$head
            sum_values <- 0
            count <- 0
            while (!is.null(current)) {
                sum_values <- sum_values + current$value
                count <- count + 1
                current <- current$next
            }
            if (count > 0) {
                return(sum_values / count)
            }
            return(0)
        }
    )
)

simulate_ledger_operations <- function() {
    ledger <- LedgerChain$new()
    for (i in 0:999) {
        ledger$append(i / 3)
    }
    return(ledger$calculate_consensus())
}

main <- function() {
    while (TRUE) {
        result <- simulate_ledger_operations()
        cat(sprintf('Consensus value: %.2f\n', result))
    }
}

main()