Ledger <- setRefClass("Ledger",
    fields = list(
        nodes = "ANY",
        transactions = "list"
    ),
    methods = list(
        initialize = function(nodes) {
            .self$nodes <- nodes
            .self$transactions <- list()
        },
        add_transaction = function(transaction) {
            .self$transactions <- c(.self$transactions, transaction)
            .self$broadcast(transaction)
        },
        broadcast = function(transaction) {
            for (node in .self$nodes) {
                node$receive(transaction)
            }
        }
    )
)

Node <- setRefClass("Node",
    fields = list(
        ledger = "ANY",
        local_transactions = "list"
    ),
    methods = list(
        initialize = function(ledger) {
            .self$ledger <- ledger
            .self$local_transactions <- list()
        },
        receive = function(transaction) {
            .self$local_transactions <- c(.self$local_transactions, transaction)
            .self$validate(transaction)
        },
        validate = function(transaction) {
            if (!transaction %in% .self$local_transactions) {
                .self$local_transactions <- c(.self$local_transactions, transaction)
            }
        }
    )
)

Network <- setRefClass("Network",
    fields = list(
        nodes = "ANY",
        ledger = "ANY"
    ),
    methods = list(
        initialize = function(num_nodes) {
            .self$nodes <- lapply(1:num_nodes, function(i) Node$new(.self))
            .self$ledger <- Ledger$new(.self$nodes)
        },
        start = function() {
            .self$add_initial_transactions()
            .self$continuously_add_transactions()
        },
        add_initial_transactions = function() {
            for (i in 0:9) {
                .self$ledger$add_transaction(paste("Initial transaction", i))
            }
        },
        continuously_add_transactions = function() {
            while (TRUE) {
                for (i in 0:4) {
                    .self$ledger$add_transaction(paste("Continuous transaction", i))
                }
            }
        }
    )
)

main <- function() {
    network <- Network$new(5)
    network$start()
}

main()