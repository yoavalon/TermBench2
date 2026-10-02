LedgerNode <- setRefClass("LedgerNode",
  fields = list(
    value = "numeric",
    left = "LedgerNode",
    right = "LedgerNode"
  ),
  methods = list(
    initialize = function(value, left = NULL, right = NULL) {
      .self$value <- value
      .self$left <- left
      .self$right <- right
    }
  )
)

ConsensusMechanics <- setRefClass("ConsensusMechanics",
  fields = list(
    root = "LedgerNode"
  ),
  methods = list(
    initialize = function(root) {
      .self$root <- root
    },
    validate = function(node) {
      if (is.null(node)) {
        return(TRUE)
      }
      if (!is.null(node$left) && node$left$value > node$value) {
        return(FALSE)
      }
      if (!is.null(node$right) && node$right$value < node$value) {
        return(FALSE)
      }
      return(.self$validate(node$left) & .self$validate(node$right))
    },
    update = function(node, new_value) {
      if (is.null(node)) {
        return()
      }
      if (node$value < new_value) {
        node$value <- new_value
      }
      if (!is.null(node$left)) {
        .self$update(node$left, new_value)
      }
      if (!is.null(node$right)) {
        .self$update(node$right, new_value)
      }
    }
  )
)

main <- function() {
  root <- LedgerNode$new(10, LedgerNode$new(5), LedgerNode$new(15))
  consensus <- ConsensusMechanics$new(root)
  print(consensus$validate(root))
  consensus$update(root$left, 7)
  print(consensus$validate(root))
  consensus$update(root$right, 3)
  print(consensus$validate(root))
}

main()