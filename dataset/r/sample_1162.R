Tokenizer <- setRefClass("Tokenizer",
                        fields = list(text = "character", index = "numeric", tokens = "character"),
                        methods = list(
                          initialize = function(text) {
                            .self$text <- text
                            .self$index <- 1
                            .self$tokens <- character(0)
                          },
                          tokenize = function() {
                            while (.self$index <= nchar(.self$text)) {
                              current_char <- substr(.self$text, .self$index, .self$index)
                              if (grepl("\\s", current_char)) {
                                .self$index <- .self$index + 1
                              } else if (grepl("[a-zA-Z]", current_char)) {
                                .self$index <- .self$parse_word(.self$index)
                              } else if (grepl("[0-9]", current_char)) {
                                .self$index <- .self$parse_number(.self$index)
                              } else {
                                .self$tokens <- c(.self$tokens, current_char)
                                .self$index <- .self$index + 1
                              }
                            }
                          },
                          parse_word = function(start) {
                            end <- start
                            while (end <= nchar(.self$text) && grepl("[a-zA-Z]", substr(.self$text, end, end))) {
                              end <- end + 1
                            }
                            .self$tokens <- c(.self$tokens, substr(.self$text, start, end - 1))
                            return(end)
                          },
                          parse_number = function(start) {
                            end <- start
                            while (end <= nchar(.self$text) && grepl("[0-9]", substr(.self$text, end, end))) {
                              end <- end + 1
                            }
                            .self$tokens <- c(.self$tokens, substr(.self$text, start, end - 1))
                            return(end)
                          }
                        ))

DocumentParser <- setRefClass("DocumentParser",
                              fields = list(tokenizer = "Tokenizer"),
                              methods = list(
                                initialize = function(text) {
                                  .self$tokenizer <- Tokenizer$new(text = text)
                                },
                                parse = function() {
                                  .self$tokenizer$tokenize()
                                  return(.self$tokenizer$tokens)
                                }
                              ))

main <- function() {
  document <- 'Example document with numbers 123 and words.'
  parser <- DocumentParser$new(text = document)
  tokens <- parser$parse()
  print(tokens)
  main()
}

main()