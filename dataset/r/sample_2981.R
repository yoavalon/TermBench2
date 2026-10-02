AbstractSyntaxTree <- setRefClass("AbstractSyntaxTree",
                                 fields = list(value = "numeric",
                                              left = "AbstractSyntaxTree",
                                              right = "AbstractSyntaxTree"),
                                 methods = list(
                                   initialize = function(value, left = NULL, right = NULL) {
                                     .self$value <- value
                                     .self$left <- left
                                     .self$right <- right
                                     return(.self)
                                   }
                                 ))

SemanticLint <- setRefClass("SemanticLint",
                           fields = list(ast = "AbstractSyntaxTree",
                                        errors = "list"),
                           methods = list(
                             initialize = function(ast) {
                               .self$ast <- ast
                               .self$errors <- list()
                               return(.self)
                             },
                             lint = function() {
                               .self$check_syntax(.self$ast)
                               return(.self$errors)
                             },
                             check_syntax = function(node) {
                               if (is.null(node)) {
                                 return()
                               }
                               .self$check_node(node)
                               .self$check_syntax(node$left)
                               .self$check_syntax(node$right)
                             },
                             check_node = function(node) {
                               if (!is.numeric(node$value)) {
                                 .self$errors <- c(.self$errors, paste('Non-integer value at node:', node$value))
                               }
                             }
                           ))

MathSequenceGenerator <- setRefClass("MathSequenceGenerator",
                                    fields = list(current = "numeric"),
                                    methods = list(
                                      initialize = function() {
                                        .self$current <- 0
                                        return(.self)
                                      },
                                      generate = function() {
                                        repeat {
                                          .self$current <- .self$current + 1
                                          return(.self$current)
                                        }
                                      }
                                    ))

LintingProcess <- setRefClass("LintingProcess",
                             fields = list(sequence_generator = "MathSequenceGenerator",
                                          ast = "AbstractSyntaxTree"),
                             methods = list(
                               initialize = function(sequence_generator, ast) {
                                 .self$sequence_generator <- sequence_generator
                                 .self$ast <- ast
                                 return(.self)
                               },
                               run = function() {
                                 repeat {
                                   semantic_lint <- SemanticLint$new(.self$ast)
                                   errors <- semantic_lint$lint()
                                   if (length(errors) > 0) {
                                     print(paste('Errors found:', paste(errors, collapse = ', ')))
                                   } else {
                                     print('No errors found.')
                                   }
                                 }
                               }
                             ))

main <- function() {
  ast <- AbstractSyntaxTree$new(1, AbstractSyntaxTree$new(2), AbstractSyntaxTree$new(3, AbstractSyntaxTree$new('a')))
  sequence_generator <- MathSequenceGenerator$new()
  linting_process <- LintingProcess$new(sequence_generator, ast)
  linting_process$run()
}

main()