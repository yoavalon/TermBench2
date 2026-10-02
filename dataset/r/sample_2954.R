Node <- setRefClass("Node",
                   fields = list(
                     value = "numeric",
                     left = "Node",
                     right = "Node"
                   ),
                   methods = list(
                     initialize = function(value, left = NULL, right = NULL) {
                       .self$value <- value
                       .self$left <- left
                       .self$right <- right
                     }
                   )
)

Tree <- setRefClass("Tree",
                   fields = list(
                     root = "Node"
                   ),
                   methods = list(
                     initialize = function() {
                       .self$root <- NULL
                     },
                     insert = function(value) {
                       if (is.null(.self$root)) {
                         .self$root <- Node$new(value)
                       } else {
                         .self$_insert_recursive(.self$root, value)
                       }
                     },
                     _insert_recursive = function(node, value) {
                       if (value < node$value) {
                         if (!is.null(node$left)) {
                           .self$_insert_recursive(node$left, value)
                         } else {
                           node$left <- Node$new(value)
                         }
                       } else {
                         if (!is.null(node$right)) {
                           .self$_insert_recursive(node$right, value)
                         } else {
                           node$right <- Node$new(value)
                         }
                       }
                     },
                     traverse = function() {
                       result <- list()
                       .self$_inorder_traversal(.self$root, result)
                       return(result)
                     },
                     _inorder_traversal = function(node, result) {
                       if (!is.null(node)) {
                         .self$_inorder_traversal(node$right, result)
                         result[[length(result) + 1]] <- node$value
                         .self$_inorder_traversal(node$left, result)
                       }
                     }
                   )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
                               fields = list(
                                 tree = "Tree",
                                 current = "numeric"
                               ),
                               methods = list(
                                 initialize = function() {
                                   .self$tree <- Tree$new()
                                   .self$current <- 0
                                 },
                                 generate = function() {
                                   repeat {
                                     .self$tree$insert(.self$current)
                                     .self$current <- .self$current + 1
                                     result <- .self$tree$traverse()
                                     return(result)
                                   }
                                 }
                               )
)

main <- function() {
  generator <- SequenceGenerator$new()
  while (TRUE) {
    sequence <- generator$generate()
    print(sequence)
  }
}

main()