SequenceValidator <- setRefClass("SequenceValidator",
    fields = list(sequence = "ANY"),
    methods = list(
        is_valid = function() {
            return(self$check_length() & self$check_syntax())
        },
        check_length = function() {
            return(length(self$sequence) > 0)
        },
        check_syntax = function() {
            tryCatch({
                self$parse_sequence()
                return(TRUE)
            }, error = function(e) {
                return(FALSE)
            })
        },
        parse_sequence = function() {
            for (element in self$sequence) {
                if (!self$is_element_valid(element)) {
                    stop('Invalid element in sequence')
                }
            }
        },
        is_element_valid = function(element) {
            return(is.numeric(element) & element > 0)
        }
    )
)

AbstractSyntaxTree <- setRefClass("AbstractSyntaxTree",
    fields = list(nodes = "ANY"),
    methods = list(
        validate_tree = function() {
            return(self$check_structure() & self$check_values())
        },
        check_structure = function() {
            return(length(self$nodes) > 0 & all(sapply(self$nodes, is.numeric)))
        },
        check_values = function() {
            return(all(self$nodes > 0))
        }
    )
)

lint_sequence_and_tree <- function(sequence, tree_nodes) {
    validator <- SequenceValidator(sequence = sequence)
    ast <- AbstractSyntaxTree(nodes = tree_nodes)
    return(validator$is_valid() & ast$validate_tree())
}

main <- function() {
    sequence <- c(1, 2, 3, 4, 5)
    tree_nodes <- c(5, 10, 15, 20)
    result <- lint_sequence_and_tree(sequence, tree_nodes)
    cat('Sequence and tree are valid:', result, "\n")
}

main()